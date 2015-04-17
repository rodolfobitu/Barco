/* ***************************************************************** */
/* File name:		 sevenSeg.h            							 */
/* File description: Header file containing the function/methods     */
/*					 prototypes of sevenSeg.c      					 */
/* Author name:      nois											 */
/* Creation date:    27mar2015										 */
/* Revision date:    27mar2015										 */
/* ***************************************************************** */

#include "sevenseg.h"
#include "mclab2.h"
#include "util.h"

/* ************************************************ */
/* Method name: 	   sevenseg_init		   		*/
/* Method description: This method configures		*/
/*					   hardware pins to work with	*/
/*					   seven segment display		*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sevenseg_init(void) {
	// Direction for multiplexer
	SEVENSEG_01_DIR = OUTPUT;
	SEVENSEG_02_DIR = OUTPUT;
	SEVENSEG_03_DIR = OUTPUT;
	SEVENSEG_04_DIR = OUTPUT;
	
	// Direction for each segment
	TRISDbits.RD0 = OUTPUT;
	TRISDbits.RD1 = OUTPUT;
	TRISDbits.RD2 = OUTPUT;
	TRISDbits.RD3 = OUTPUT;
	TRISDbits.RD4 = OUTPUT;
	TRISDbits.RD5 = OUTPUT;
	TRISDbits.RD6 = OUTPUT;
	TRISDbits.RD7 = OUTPUT;
}

/* ************************************************ */
/* Method name: 	   sevenseg_set         		*/
/* Method description: set the desired seven segment*/
/*					   to a value					*/
/* Input params:	   cLedNum    = which LED {1..4}*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sevenseg_set(char cSSNum, sevenseg_value_e eValue) {
	SEVENSEG_01 = LED_OFF;
	SEVENSEG_02 = LED_OFF;
	SEVENSEG_03 = LED_OFF;
	SEVENSEG_04 = LED_OFF;

	switch (cSSNum) {
		case 1: SEVENSEG_01 = LED_ON; break;
		case 2: SEVENSEG_02 = LED_ON; break;
		case 3: SEVENSEG_03 = LED_ON; break;
		case 4: SEVENSEG_04 = LED_ON; break;
		default:					  break;
	}
	
	switch (eValue) {
		case SEVENSEG_CLEAR: PORTD = 0b00000000; break;
		case SEVENSEG_0:     PORTD = 0b00111111; break;
		case SEVENSEG_1:     PORTD = 0b00000110; break;
		case SEVENSEG_2:     PORTD = 0b01011011; break;
		case SEVENSEG_3:     PORTD = 0b01001111; break;
		case SEVENSEG_4:     PORTD = 0b01100110; break;
		case SEVENSEG_5:     PORTD = 0b01101101; break;
		case SEVENSEG_6:     PORTD = 0b01111101; break;
		case SEVENSEG_7:     PORTD = 0b00000111; break;
		case SEVENSEG_8:     PORTD = 0b01111111; break;
		case SEVENSEG_9:     PORTD = 0b01101111; break;
		case SEVENSEG_A:     PORTD = 0b00100111; break;
		case SEVENSEG_B:     PORTD = 0b00111100; break;
		case SEVENSEG_C:     PORTD = 0b00111001; break;
		case SEVENSEG_D:     PORTD = 0b01011110; break;
		case SEVENSEG_E:     PORTD = 0b01111001; break;
		case SEVENSEG_F:     PORTD = 0b01110001; break;
		default:			 PORTD = 0b10000000; break;
	}
}

/* ************************************************ */
/* Method name: 	   sevenseg_setWithInt     		*/
/* Method description: set 7seg with an int			*/
/*					 								*/
/* Input params:	   iValue = int {0..9999}		*/
/*					   								*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void sevenseg_setWithInt (int iValue){
	int u;
	int d;
	int c;
	int m;

	u = iValue%10;
	iValue /= 10;
	d = iValue%10;
	iValue /= 10;
	c = iValue%10;
	iValue /= 10;
	m = iValue%10;
	
	sevenseg_set(1, m ? m:SEVENSEG_CLEAR);
	util_genDelay10MS();

	sevenseg_set(2, c || m ? c : SEVENSEG_CLEAR);
	util_genDelay10MS();

	sevenseg_set(3, d || c || m ? d : SEVENSEG_CLEAR);
	util_genDelay10MS();

	sevenseg_set(4, u);
	util_genDelay10MS();


}

