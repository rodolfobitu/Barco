/* ***************************************************************** */
/* File name:		 util.c                  						 */
/* File description: This file has a couple of useful functions to   */
/*					 make programming more productive			     */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    07mai2015										 */
/* ***************************************************************** */

#include "util.h"
#include "mclab2.h"

/*
FOSC = 48 MHz
tick = 1 / (FOSC/4)
count = time [ms] / tick
timer = 65536 - (Count/prescale)

OR
timer = 65536 - ( (tempo/ (1 / (FOSC/4))) / ps)
*/

/* timer config for 100ms */
#define UTIL_TIMER0_TEMPO 				1000
#define UTIL_TIMER0_FOSC				48000
#define UTIL_TIMER0_PS					256
#define UTIL_TIMER0_RESET_VALUE 		60849
#define UTIL_TIMER0_RESET_VALUE_HIGH    ((UTIL_TIMER0_RESET_VALUE & 0xff00) >> 8)
#define UTIL_TIMER0_RESET_VALUE_LOW 	( UTIL_TIMER0_RESET_VALUE & 0x00ff)


/* ************************************************ */
/* Method name: 	   util_genDelay1MS      		*/
/* Method description: generates ~ 1ms delay        */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay1MS(void)
{
	char i;
	for(i=0; i<69; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}


/* ************************************************ */
/* Method name: 	   util_genDelay10MS      		*/
/* Method description: generates ~ 10ms delay       */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay10MS(void)
{
	char i;
	for(i=0; i<9; i++)
		util_genDelay1MS();
	for(i=0; i<59; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}


/* ************************************************ */
/* Method name: 	   util_genDelay100MS      		*/
/* Method description: generates ~ 100ms delay      */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay100MS(void)
{
	char i;
	for(i=0; i<9; i++)
		util_genDelay10MS();
	for(i=0; i<9; i++)
		util_genDelay1MS();
	for(i=0; i<49; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}


/* ************************************************ */
/* Method name: 	   util_genDelay500MS      		*/
/* Method description: generates ~ 500ms delay      */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay500MS(void)
{
	char i;
	for(i=0; i<4; i++)
		util_genDelay100MS();
	for(i=0; i<9; i++)
		util_genDelay10MS();
	for(i=0; i<9; i++)
		util_genDelay1MS();
	for(i=0; i<44; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}



/* ************************************************ */
/* Method name: 	   util_resetCyclicExecutive    */
/* Method description: reset the TIMER0 high and low*/
/*                     values                       */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_resetCyclicExecutive(void) 
{
	TMR0H = UTIL_TIMER0_RESET_VALUE_HIGH;
  	TMR0L = UTIL_TIMER0_RESET_VALUE_HIGH;
}



/* ************************************************ */
/* Method name: 	   util_configCyclicExecutive   */
/* Method description: configures the Cyclic Executive*/
/*                     timer interruption = 100ms   */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_configCyclicExecutive(void)
{
	INTCONbits.GIE = 1;		// enables all unmasked interrupts
  	INTCONbits.PEIE = 1;	// enables all unmasked peripheral interrupts
  	INTCONbits.TMR0IE = 1; 	// enables TMR0 overflow interrup
  	
  	T0CONbits.T08BIT = 0; 	// 16-bit timer
  	T0CONbits.T0CS = 0; 	// internal clock (FOSC/4)
  	T0CONbits.PSA = 0; 		// prescaler assigned
  	T0CONbits.T0PS = 0b111; // 1:256 prescale

  	util_resetCyclicExecutive();

  	T0CONbits.TMR0ON = 1; 	// enables TMR0
}



/* ************************************************ */
/* Method name: 	   util_initTimer1AsCounter  	*/
/* Method description: configure TIMER1             */
/*                     to be a 16b counter          */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_initTimer1AsCounter(void)
{
	T1CONbits.RD16 = 1; 		// 16-bit operation
  	T1CONbits.T1RUN = 0; 		// Device clock from another source (COOLER from target)
  	T1CONbits.T1CKPS = 0; 		// 1:1 prescaler
  	T1CONbits.T1OSCEN = 0; 		// oscilator is off
  	T1CONbits.NOT_T1SYNC = 1; 	// do not synchronize
  	T1CONbits.TMR1CS = 1; 		// external clock source (rising edge)  	
  	T1CONbits.TMR1ON = 0; 		// disable timer1
  	
  	util_resetTimer1Counter();

}



/* ************************************************ */
/* Method name: 	   util_resetTimer1Counter  	*/
/* Method description: reset the count of TIMER1    */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_resetTimer1Counter(void)
{
  	/* reset any previous counter */
  	TMR1H = 0;
  	TMR1L = 0;
}



/* ************************************************ */
/* Method name: 	   util_startTimer1Counter  	*/
/* Method description: init the counting            */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_startTimer1Counter(void)
{
	T1CONbits.TMR1ON = 1; 		// enable timer1
}



/* ************************************************ */
/* Method name: 	   util_stopTimer1Counter  		*/
/* Method description: stop the counting            */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_stopTimer1Counter(void)
{
	T1CONbits.TMR1ON = 0; 		// disable timer1
}



/* ************************************************ */
/* Method name: 	   util_getTimer1Count  	    */
/* Method description: return the counting value    */
/*                     related to TIMER1 as counter */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
unsigned int util_getTimer1Count(void)
{
	unsigned int uiCount;
	unsigned int uiCountLow;
  
  	/* return the MSB + LSB parts */
	uiCountLow = TMR1L;
  	uiCount = (((unsigned int)TMR1H) << 8) + uiCountLow;
  
  	return uiCount;
}



/* ************************************************ */
/* Method name: 	   util_convertFromUi2Ascii     */
/* Method description: Convert from unsigned int to */
/*                     ASCII                        */
/* Input params:	   uiVal => number to be converted*/
/* Outpu params:	   *cStr => number converted	*/
/* ************************************************ */
void util_convertFromUi2Ascii(unsigned int uiVal, char *cStr)
{
  if (uiVal >= 10000)
    *cStr++ = (uiVal/10000 % 10) + '0';
  
  if (uiVal >= 1000)
    *cStr++ = (uiVal/1000 % 10) + '0';
  
  if (uiVal >= 100)
    *cStr++ = (uiVal/100 % 10) + '0';
  
  if (uiVal >= 10)
    *cStr++ = (uiVal/10 % 10) + '0';
  
  *cStr++ = (uiVal % 10) + '0';
  *cStr = 0;
}
