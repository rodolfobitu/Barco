/* ***************************************************************** */
/* File name:		 mclab2.h							 			 */
/* File description: Header file containing the peripherals mapping  */
/*					 of the target development kit MCLAB2 V5.0		 */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    09jan2015										 */
/* ***************************************************************** */

#ifndef MCLAB2_H
#define MCLAB2_H

/* uC registers definition */
#include <p18F4550.h>

/* port directions */
#define INPUT			1
#define OUTPUT			0

/* switches definition */
#define SWITCH_01		PORTBbits.RB0
#define SWITCH_01_DIR	TRISBbits.RB0

#define SWITCH_02		PORTBbits.RB1
#define SWITCH_02_DIR	TRISBbits.RB1

#define SWITCH_03		PORTBbits.RB2
#define SWITCH_03_DIR	TRISBbits.RB2

#define SWITCH_04		PORTBbits.RB3
#define SWITCH_04_DIR	TRISBbits.RB3


/* LEDs definition */
#define LED_ON		1
#define LED_OFF		0

#define LED_01			SWITCH_01
#define LED_01_DIR		SWITCH_01_DIR

#define LED_02			SWITCH_02
#define LED_02_DIR		SWITCH_02_DIR

#define LED_03			SWITCH_03
#define LED_03_DIR		SWITCH_03_DIR

#define LED_04			SWITCH_04
#define LED_04_DIR		SWITCH_04_DIR


/* 7 Seg Diplays definition */

#define SEVENSEG_01		PORTBbits.RB7
#define SEVENSEG_02		PORTBbits.RB6
#define SEVENSEG_03		PORTBbits.RB5
#define SEVENSEG_04		PORTBbits.RB4

#define SEVENSEG_01_DIR	TRISBbits.RB7
#define SEVENSEG_02_DIR	TRISBbits.RB6
#define SEVENSEG_03_DIR	TRISBbits.RB5
#define SEVENSEG_04_DIR	TRISBbits.RB4


#define NUMBER1			0b0000110


#endif /* MCLAB2_H */
