/* ***************************************************************** */
/* File name:		 es670.c							 			 */
/* File description: Main file for the ES670 Practical Project		 */
/* Author name:      dloubach										 */
/* Creation date:    20jan2015										 */
/* Revision date:    06mar2015										 */
/* ***************************************************************** */

#include "es670_pp.h"
#include "mclab2.h"
#include "ledswi.h"
#include "sevenseg.h"
#include "util.h"
#include "serialcom.h"
#include "cmdMachine.h"

/* uC init configurations */

/* uC @ 48 MHz */
#pragma config PLLDIV = 1 			//Divide by 1 (04 MHz oscillator input) 
#pragma config CPUDIV = OSC1_PLL2 	//96 MHz PLL Src: /2
#pragma config FOSC   = XTPLL_XT	//XT oscillator, PLL enabled

#pragma config IESO   = OFF			//Oscillator Switchover mode disabled 
#pragma config PWRT   = ON			//Power-up Timer enabled
#pragma config BOR    = ON			//Brown-out Reset enabled
#pragma config BORV   = 0			//Brown-out Reset to maximum setting
#pragma config WDT    = OFF			//Watchdog timer disabled
#pragma config LVP    = OFF			//Single-Supply ICSP disabled


/* ************************************************ */
/* Method name: 	   runInitialization		    */
/* Method description: takes care of uC intial      */
/*					   configurations				*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void runInitialization(void) {
	/* clean all ports */
	PORTA = CLEAN_DATA;
	PORTB = CLEAN_DATA;
	PORTC = CLEAN_DATA;
	PORTD = CLEAN_DATA;
	PORTE = CLEAN_DATA;
	
	/* ADC off */
	ADCON1 = ADC_OFF;
	
	/* init leds and switches */
	ledswi_initLedSwitch(02, 02);

	sevenseg_init();
	sc_init();
}


/* ************************************************ */
/* Method name: 	   main						    */
/* Method description: main program function        */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void main(void) {
	
	/* run uC init configs */
	runInitialization();

	sc_start();
	
	/* main loop */
	while(TRUE) {
		char* buffer[50];
		sc_receiveBuffer(buffer);
		sc_sendBuffer(buffer);
		cm_interpretCmd(buffer);
	}
}
