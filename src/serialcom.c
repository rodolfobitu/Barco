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
#include <ctype.h>

/* ************************************************ */
/* Method name: 	   sc_init		   		*/
/* Method description: This method configures		*/
/*					   hardware pins to work with	*/
/*					   serial communication		*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_init(void) {
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
/* Method name: 	   sc_receiveBuffer		   		*/
/* Method description: Receive a buffer using serial*/
/* 						communication.				*/
/* Input params:	   char* cBuf					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_receiveBuffer(char cBuf[]) {
	int i=0;
	while (1) {
		// Check if we're ready
		if (PIR1bits.RCIF) {
			char temp = RCREG; 
			// Check if we're done
			if (isprint(temp)){
				cBuf[i] = temp;
				i++;
			} else if (temp == 8){
				i--;
				if (i<0) i = 0;
			}else{
				//we're done
				cBuf[i] = '\0';
				break;
			}
			
		}
	}
}


