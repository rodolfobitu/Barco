/* ***************************************************************** */
/* File name:		 pwm.c							 			 	 */
/* File description: File dedicated to the function implementation   */
/*                   related to PWM module from the uC target        */
/* Author name:      dloubach										 */
/* Creation date:    14mai2015										 */
/* Revision date:    14mai2015										 */
/* ***************************************************************** */

#include "pwm.h"
#include "mclab2.h"

/* constant for PWM module activation */
#define PWM_MODE_MASK 	0x0C

/* duty cycle shift and maks definitions */
#define PWM_DC_SHIFT 	0x02
#define PWM_DC_MASK 	0x3FF


/* ************************************************ */
/* Method name: 	   pwm_initPwm					*/
/* Method description: initialize the PWM configs   */
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void pwm_initPwm(void)
{
	/*
	 * Target is built to use CCP2 PWM module to
	 * activate the cooler
	 */
	
	/* configure PWM frequency for 46.875 kHz*/
	PR2 = 255;		// TMR2 counter
	T2CON &= 0xFC;	// TMR2 prescaler configuration = 1 1111-1100
	
  	/* configure initial duty cycle */
  	pwm_setDutyCycle(PWM_INIT_DC);
	
	/* configure the COOLER direction */ 
	COOLER = 0x0;
	COOLER_DIR = OUTPUT;
	
	/* enable TMR2 */
	T2CONbits.TMR2ON = 1;
	
	/* CCPxM3:CCPxM2 = 11 => PWM mode */
	CCP2CON |= PWM_MODE_MASK;
}



/* ************************************************ */
/* Method name: 	   pwm_setDutyCycle				*/
/* Method description: configure PWM duty cycle     */
/* Input params:	   uiDutyCycle => duty cyle value*/
/*                     from 0 to 2^10 -1			*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void pwm_setDutyCycle(const unsigned int uiDutyCycle)
{
	CCPR2L = ((uiDutyCycle & PWM_DC_MASK) >> PWM_DC_SHIFT);
  	CCP2CONbits.DC2B = (uiDutyCycle & PWM_DC_SHIFT);
}
