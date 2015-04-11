/* ***************************************************************** */
/* File name:		 serialcom.c            							 */
/* File description: Works with serial communication 					 */
/* Author name:      nois											 */
/* Creation date:    10abr2015										 */
/* Revision date:    10abr2015										 */
/* ***************************************************************** */

#include "serialcom.h"
#include "mclab2.h"

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