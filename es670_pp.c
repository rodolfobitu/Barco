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
#include "util.h"

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
void runInitialization(void)
{
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
}


/* ************************************************ */
/* Method name: 	   main						    */
/* Method description: main program function        */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void main(void)
{
	
	char gui = 0;

	switch_status_type_e sstSwitch01;
	switch_status_type_e sstSwitch02;
	
	/* run uC init configs */
	runInitialization();
	
	/* play with leds */
	ledswi_setLed(04);
	
	SEVENSEG_01_DIR = OUTPUT;
	SEVENSEG_02_DIR = OUTPUT;
	SEVENSEG_03_DIR = OUTPUT;
	SEVENSEG_04_DIR = OUTPUT;
	
	TRISDbits.RD0 = OUTPUT;
	TRISDbits.RD1 = OUTPUT;
	TRISDbits.RD2 = OUTPUT;
	TRISDbits.RD3 = OUTPUT;
	TRISDbits.RD4 = OUTPUT;
	TRISDbits.RD5 = OUTPUT;
	TRISDbits.RD6 = OUTPUT;
	TRISDbits.RD7 = OUTPUT;

	/* main loop */
	while(TRUE)
	{
		
		PORTD = NUMBER1;

		/* if switch01 is ON, LED03 will be ON */
		sstSwitch01 = ledswi_getSwitchStatus(01);
		
		if(SWITCH_ON == sstSwitch01){
			ledswi_setLed(03);

		}
		else{
			ledswi_clearLed(03);
		}

		gui = (gui+1)%4;
		SEVENSEG_01 = LED_OFF;
		SEVENSEG_02 = LED_OFF;
		SEVENSEG_03 = LED_OFF;
		SEVENSEG_04 = LED_OFF;
		switch (gui) {
			case 0:
				SEVENSEG_01 = LED_ON;
				break;
			case 1:
				SEVENSEG_02 = LED_ON;
				break;
			case 2:
				SEVENSEG_03 = LED_ON;
				break;
			case 3:
				SEVENSEG_04 = LED_ON;
				break;
		}
		
		/* 100ms delay */	
		util_genDelay10MS();

		
	}
}
