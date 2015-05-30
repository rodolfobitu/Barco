/* ***************************************************************** */
/* File name:		 es670_pp.c							 			 */
/* File description: Main file for the ES670 Practical Project		 */
/* Author name:      dloubach										 */
/* Creation date:    20jan2015										 */
/* Revision date:    22mai2015										 */
/* ***************************************************************** */

#include "es670_pp.h"
#include "mclab2.h"
#include "ledswi.h"
#include "util.h"
#include "lcd.h"
#include "cooler.h"
#include "sevenseg.h"
#include "serialcom.h"
#include "cmdMachine.h"
#include "buzzer.h"
#include "pwm.h"
#include "adc.h"

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


/* globals */
volatile unsigned int uiFlagNextPeriod = 0;	// cyclic executive flag

/* state machine related to ADC task */
#define ADC_TASK_STATE_INIT			0
#define ADC_TASK_STATE_CONVERTING	1
#define ADC_TASK_STATE_DONE			2

/* transfer equation for AD to Temperature 
 * f(y) = ax + b 
 * the parameters apply only in the range 
 * ~28ºC to ~89ºC
 * ADC_TRANSF_EQ_LOW_LIM to ADC_TRANSF_EQ_HIG_LIM
 * which could be obtained when heater is in 50% duty cycle PWM
 */
#define ADC_TRANSF_EQ_LOW_LIM		350
#define ADC_TRANSF_EQ_HIG_LIM		500
#define ADC_TRANSF_EQ_PARAM_A		0.4073
#define ADC_TRANSF_EQ_PARAM_B		-123.75



/* setup the interruption */
void isr_CyclicExecutive();
#pragma code high_vector=0x08
void isr_HighVector(void)
{
  _asm GOTO isr_CyclicExecutive _endasm
}
#pragma code


/* setup the isr */
#pragma interrupt isr_CyclicExecutive
void isr_CyclicExecutive(void) {
	if (INTCONbits.TMR0IF) {
		/* set the cyclic executive flag */
		uiFlagNextPeriod = 1;

		/* reset the cyclic executive counting */
		util_resetCyclicExecutive();

		/* acknowledge the interrupt */
		INTCONbits.TMR0IF = 0;
	}
	
	if (PIR1bits.RCIF) {
		sc_read();
	}
	
	if (PIR1bits.TXIF){
		sc_send();
	}
}



/* ************************************************ */
/* Method name: 	   es670_runInitialization		*/
/* Method description: takes care of uC intial      */
/*					   configurations				*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_runInitialization(void)
{
	/* clean all ports */
	PORTA = CLEAN_DATA;
	PORTB = CLEAN_DATA;
	PORTC = CLEAN_DATA;
	PORTD = CLEAN_DATA;
	PORTE = CLEAN_DATA;
	
	/* init ADC */
	adc_initAdc();
		
	/* init leds and switches */
	ledswi_initLedSwitch(02, 02);
	
	sevenseg_init();
	sc_init();
	bz_init();
	
	/* init LCD */
	lcd_initLcd();
	
	/* init cooler */
	cooler_initCooler();
	
	/* init TIMER1 as counter, 
	 * used for counting the number of pulses
	 * originated from the cooler
	 */
	util_initTimer1AsCounter();
	
	/* init PWM module for cooler */
	pwm_initPwm(PWM_COOLER);
	
	/* init PWM module for heater */
//	pwm_initPwm(PWM_HEATER);
	/* set DC for heater PWM in 50% */
//	pwm_setDutyCycle(PWM_DC_50, PWM_HEATER);
}



/* ************************************************ */
/* Method name: 	   es670_prepare			    */
/* Method description: prepare things before execute*/
/*					   the main program loop 		*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_prepare(void)
{	
	unsigned int i;
	char cLine1[] = "COOLER VELOCITY & TEMPERATURE \n\r";
	
	/* write something in the LCD */
	lcd_sendCommand(CMD_CLEAR);
	lcd_setCursor(0,0);
	lcd_dummyText();
	for(i=0; i<10; i++)
		util_genDelay500MS();
	
	/* play with leds */
	ledswi_setLed(04);
	
	/* init TIMER1 counter */
	util_startTimer1Counter();
	
	/* zero speed samples */
	for (i=0; i<UTIL_1S_ITERATION_NUM; i++) {
		speedSamples[i] = 0;
	}
}



/* ************************************************ */
/* Method name: 	   es670_coolerTask			    */
/* Method description: this task (method) plays with*/
/*					   the cooler installed on target*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_coolerTask(void)
{
	static char prevCooler = COOLER_OFF;
	switch_status_type_e sstSwitch;
	
	/* if switch01 is ON, cooler is turned on */
	sstSwitch = ledswi_getSwitchStatus(01);
	if(SWITCH_ON == sstSwitch && COOLER_OFF == prevCooler)
	{
		/* also reset the counter */
		util_resetTimer1Counter();
		
		/* turn cooler on */
		cooler_turnOnOff(COOLER_ON);
		prevCooler = COOLER_ON;
	}
			
	/* if switch02 is ON, cooler is turned off */
	sstSwitch = ledswi_getSwitchStatus(02);
	if(SWITCH_ON == sstSwitch && COOLER_ON == prevCooler) {
		cooler_turnOnOff(COOLER_OFF);
		prevCooler = COOLER_OFF;
	}
}

/* ************************************************ */
/* Method name: 	   es670_commandMachineTask	    */
/* Method description: this task (method) plays with*/
/*					   the command machine and serial com*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_commandMachineTask(void)
{
	char cBuf[100];
	sc_readLine(cBuf);
	cm_interpretCmd(cBuf);
	
}

/* ************************************************ */
/* Method name: 	   es670_computeCoolerVelocity  */
/* Method description: compute the cooler speed in  */
/*					   RPS (revolutions per second) */
/*													*/
/*                     Period = 1 s                 */
/*													*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_computeCoolerVelocity(void) {
	int i;
	char text[10];
	
	/* Save the current speed sample and reset the counter */
	speedSamples[speedIndex++] = util_getTimer1Count();
	speedIndex %= UTIL_1S_ITERATION_NUM;
	util_resetTimer1Counter();
	
	/* Compute the current speed in RPS */
	for (i=0; i<UTIL_1S_ITERATION_NUM; i++) {
		speed += speedSamples[i];
	}
	speed /= COOLER_BLADES_NUM;
	
	cm_setSpeed(speed);
	
	
}


/* ************************************************ */
/* Method name: 	   main						    */
/* Method description: main program function        */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void main(void)
{
	/* run uC init configs */
	es670_runInitialization();
	
	/* prepare something before entering the main loop */
	es670_prepare();
	
	/* config and start the cyclic executive */
	util_configCyclicExecutive();
				
	/* main system loop, runs forever */
	while(TRUE)
	{
		/* compute cooler velocity task */
		es670_computeCoolerVelocity();
		
		/* cooler task */
		es670_coolerTask();
		
		es670_commandMachineTask();

		/* WAIT FOR CYCLIC EXECUTIVE PERIOD */
		while(!uiFlagNextPeriod);
		uiFlagNextPeriod = 0;
		
	} /* while(TRUE) */
}
