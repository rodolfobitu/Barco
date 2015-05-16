/* ***************************************************************** */
/* File name:		 serialcom.c            							 */
/* File description: Works with serial communication 					 */
/* Author name:      nois											 */
/* Creation date:    10abr2015										 */
/* Revision date:    10abr2015										 */
/* ***************************************************************** */

#include "serialcom.h"
#include "mclab2.h"
#include "util.h"
#include "es670_pp.h"
#include <ctype.h>

#define BUFFER_LEN 100

/* file locals */
static char RCBuffer[BUFFER_LEN];
static char RCBufferI = 0;
static char RCBufferLastRead = 0;

static char TXBuffer[BUFFER_LEN];
static char TXBufferI = 0;
static char TXBufferIToSend = 0;
static char TXSendEnabled = FALSE;

/* ************************************************ */
/* Method name: 	   sc_init		   		*/
/* Method description: This method configures		*/
/*					   hardware pins to work with	*/
/*					   serial communication		*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_init(void) {
	int i;
	TRISCbits.RC7 = INPUT;
	TRISCbits.RC6 = INPUT;
	
	TXSTAbits.TX9 = 0;
	TXSTAbits.TXEN = 1;
	TXSTAbits.SYNC = 0;
	TXSTAbits.BRGH = 0;
	
	RCSTAbits.SPEN = 1;
	RCSTAbits.RX9 = 0;
	RCSTAbits.CREN = 1;
	
	BAUDCONbits.BRG16 = 0;
	
	SPBRGH = 0;
	SPBRG = 77;

	for (i=0;i<100;i++){
		RCBuffer[i] = 'A';
	}

}

/* ************************************************ */
/* Method name: 	   sc_start		   		*/
/* Method description: Sends '$' until we receive 'A' */
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_start(void) {
	while (1) {
		// Send
		TXREG = '$';
		
		// Check if we're done
		if (PIR1bits.RCIF && RCREG == 'A') {
			break;
		}
		
		util_genDelay100MS();
	}
}

/* ************************************************ */
/* Method name: 	   sc_sendBuffer		   		*/
/* Method description: Sends buffer using the serial*/
/* 						communication.				*/
/* Input params:	   char* cBuf					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_sendBuffer(char cBuf[]) {
	int i = 0;

	while (cBuf[i] != '\0') {
		util_genDelay100MS();
		while (!PIR1bits.TXIF);
		TXREG = cBuf[i++];
	}
}

/* ************************************************ */
/* Method name: 	   sc_send		   		*/
/* Method description: Sends a char from TXBuffer using */
/* 						the serial communication.	*/
/* Input params:	   char* cBuf					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_send(void) {
	if (TXSendEnabled && PIR1bits.TXIF){
		TXREG = TXBuffer[TXBufferIToSend++];
		if (TXBufferIToSend == TXBufferI){
			TXSendEnabled = FALSE;
			TXBufferI = TXBufferIToSend = 0;
		}
	}
}

/* ************************************************ */
/* Method name: 	   sc_sendLine					*/
/* Method description: Populate TXBuffer with a cBuf*/
/*						to be send					*/
/* Input params:	   char* cBuf					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_sendLine(char* cBuf) {
	int i=0;
	
	while (cBuf[i] != '\0') {
		TXBuffer[TXBufferI++] = cBuf[i];
		i++;
	}
	TXSendEnabled = TRUE;
	sc_send();
	
}

/* ************************************************ */
/* Method name: 	   sc_read						*/
/* Method description: Read a single char from		*/
/*						RCREG, if available			*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_read(void) {
	if (PIR1bits.RCIF) {
		char temp = RCREG;
		
		if (isprint(temp)) {
			RCBuffer[RCBufferI++] = temp;
		} else if (temp == '\b') {
			if (RCBufferI != RCBufferLastRead) {
				RCBufferI--;
			}
		} else {
			// End of line
			RCBuffer[RCBufferI++] = '\0';
		}
		
		// Our buffer is circular
	/*	if (RCBufferI < 0) {
			RCBufferI += BUFFER_LEN;
		} else if (RCBufferI >= BUFFER_LEN) {
			RCBufferI -= BUFFER_LEN;
		}*/
	}
}

/* ************************************************ */
/* Method name: 	   sc_readLine		   		*/
/* Method description: Write the next received line */
/*						into input buffer. If no	*/
/*						has been received, the is	*/
/*						emptied						*/
/* Input params:	   char cBuf[]					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_readLine(char cBuf[]) {
	char i, j, k, end = -1, sawEnd = FALSE;
	
	/* Check whether there is a line in the circular buffer */
	for (i = RCBufferLastRead; i != RCBufferI; ) {
		if (!RCBuffer[i]) {
			if (!sawEnd) {
				sawEnd = TRUE;
				end = i;
			}
		} else {
			if (sawEnd) {
				break;
			}
		}
		
		i++;
	/*	if (i >= BUFFER_LEN) {
			i -= BUFFER_LEN;
		}*/
	}
	
	if (end == -1) {
		/* No line yet */
		cBuf[0] = '\0';
		return;
	}
	
	/* Copy the line */
	for (j = RCBufferLastRead, k = 0; j != end; ) {
		cBuf[k++] = RCBuffer[j++];
	/*	if (j >= BUFFER_LEN) {
			j -= BUFFER_LEN;
		}*/
	}
	cBuf[k] = '\0';
	RCBufferLastRead = i;
	if (i == RCBufferI){
		RCBufferI = RCBufferLastRead = 0;
	}
	return;
}
