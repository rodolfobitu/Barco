/* ***************************************************************** */
/* File name:		 ledswi.c                  						 */
/* File description: This file has a couple of useful functions to   */
/*					 control LEDs and Switches from MCLAB2 dev kit   */
/* Author name:      dloubach										 */
/* Creation date:    20jan2015										 */
/* Revision date:    20jan2015										 */
/* ***************************************************************** */

#include "ledswi.h"
#include "mclab2.h"

/* ************************************************ */
/* Method name: 	   ledswi_initLedSwitch   		*/
/* Method description: As the hardware board was    */
/*					   designed with LEDs/Switches  */
/*					   sharing the same pins, this  */
/*					   method configures how many   */
/*					   LEDS and switches will be    */
/*					   available for the application*/
/* Input params:	   cLedNum    = num of LEDs     */
/*					   cSwitchNum = num of Switches */
/*					   cLedNum + 				    */
/*					   cSwitchNum <= MAX_LED_SWI	*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_initLedSwitch(char cLedNum, char cSwitchNum)
{
	/* check if the number to configured is according to 
	hardware dev kit */
	if((cLedNum + cSwitchNum) <= MAX_LED_SWI)
	{
		/* max number of peripherals to configure is ok, carry on */
		switch(cSwitchNum)
		{
			case 0:
				LED_01_DIR = OUTPUT;
				LED_02_DIR = OUTPUT;
				LED_03_DIR = OUTPUT;
				LED_04_DIR = OUTPUT;
				break;
				
			case 1:
				SWITCH_01_DIR = INPUT;
				LED_02_DIR = OUTPUT;
				LED_03_DIR = OUTPUT;
				LED_04_DIR = OUTPUT;
				break;
				
			case 2:
				SWITCH_01_DIR = INPUT;
				SWITCH_02_DIR = INPUT;
				LED_03_DIR = OUTPUT;
				LED_04_DIR = OUTPUT;
				break;
				
			case 3:
				SWITCH_01_DIR = INPUT;
				SWITCH_02_DIR = INPUT;
				SWITCH_03_DIR = INPUT;
				LED_04_DIR = OUTPUT;
				break;
				
			case 4:
				SWITCH_01_DIR = INPUT;
				SWITCH_02_DIR = INPUT;
				SWITCH_03_DIR = INPUT;
				SWITCH_04_DIR = INPUT;
				break;		
		} /* switch(cSwitchNum) */		
	
	} /* if((cLedNum + cSwitchNum) <= MAX_LED_SWI) */

}


/* ************************************************ */
/* Method name: 	   ledswi_setLed         		*/
/* Method description: set the led ON               */
/* Input params:	   cLedNum    = which LED {1..4}*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_setLed(char cLedNum)
{
	/* sanity check */
	if(cLedNum <= MAX_LED_SWI)
	{
		switch(cLedNum)
		{
			case 1:
				LED_01 = LED_ON;
				break;
			case 2:
				LED_02 = LED_ON;
				break;
			case 3:
				LED_03 = LED_ON;
				break;
			case 4:
				LED_04 = LED_ON;
				break;
		} /* switch(cLedNum) */
	
	} /* if(cLedNum <= MAX_LED_SWI) */
}


/* ************************************************ */
/* Method name: 	   ledswi_clearLed         		*/
/* Method description: set the led OFF              */
/* Input params:	   cLedNum    = which LED {1..4}*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_clearLed(char cLedNum)
{
	/* sanity check */
	if(cLedNum <= MAX_LED_SWI)
	{
		switch(cLedNum)
		{
			case 1:
				LED_01 = LED_OFF;
				break;
			case 2:
				LED_02 = LED_OFF;
				break;
			case 3:
				LED_03 = LED_OFF;
				break;
			case 4:
				LED_04 = LED_OFF;
				break;
		} /* switch(cLedNum) */
	
	} /* if(cLedNum <= MAX_LED_SWI) */
}


/* ************************************************ */
/* Method name: 	   ledswi_getSwitchStatus	    */
/* Method description: return the switch status     */
/* Input params:	   cSwitchNum = which switch    */
/* Outpu params:	   switch_status_type_e			*/
/* ************************************************ */
switch_status_type_e ledswi_getSwitchStatus(char cSwitchNum)
{
	switch_status_type_e sstReturn = SWITCH_OFF;
	
	/* sanity check */
	if(cSwitchNum <= MAX_LED_SWI)
	{
		switch(cSwitchNum)
		{
			case 1:
				if(SWITCH_ON == SWITCH_01)
					sstReturn = SWITCH_ON;
				break;
			
			case 2:
				if(SWITCH_ON == SWITCH_02)
					sstReturn = SWITCH_ON;
				break;
				
			case 3:
				if(SWITCH_ON == SWITCH_03)
					sstReturn = SWITCH_ON;
				break;
				
			case 4:
				if(SWITCH_ON == SWITCH_04)
					sstReturn = SWITCH_ON;
				break;
		
		} /* switch(cSwitchNum) */
		
		/* return the result */
		return(sstReturn);
		
	} /* if(cSwitchNum <= MAX_LED_SWI) */

}
