/* ***************************************************************** */
/* File name:		 pwm.h							 			 	 */
/* File description: Header file containing the functions/methods    */
/*					 interfaces for handling the PWM module from uC  */
/* Author name:      dloubach										 */
/* Creation date:    14mai2015										 */
/* Revision date:    22mai2015										 */
/* ***************************************************************** */

#ifndef PWM_H
#define PWM_H

/* duty cycle definitions */
#define PWM_DC_100		1023 /* (2^10)-1 */
#define PWM_DC_75		767
#define PWM_DC_50		511
#define PWM_DC_25		255
#define PWM_DC_00		0
#define PWM_INIT_DC		PWM_DC_00

#define PWM_COOLER		0
#define PWM_HEATER		1

/* ************************************************ */
/* Method name: 	   pwm_initPwm					*/
/* Method description: initialize the PWM configs   */
/* Input params:	   ucDevice => PWM_COOLER       */
/*                              => PWM_HEATER       */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void pwm_initPwm(unsigned char ucDevice);


/* ************************************************ */
/* Method name: 	   pwm_setDutyCycle				*/
/* Method description: configure PWM duty cycle     */
/* Input params:	   uiDutyCycle => duty cyle value*/
/*                     from 0 to 2^10 -1			*/
/*              	   ucDevice => PWM_COOLER       */
/*                              => PWM_HEATER       */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void pwm_setDutyCycle(const unsigned int uiDutyCycle,
					  unsigned char ucDevice);


#endif /* PWM_H */
