/* ***************************************************************** */
/* File name:		 mclab2.h							 			 */
/* File description: Header file containing the peripherals mapping  */
/*					 of the target development kit MCLAB2 V5.0		 */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    04mai2015										 */
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

#define SEVENSEG_01		PORTBbits.RB7
#define SEVENSEG_02		PORTBbits.RB6
#define SEVENSEG_03		PORTBbits.RB5
#define SEVENSEG_04		PORTBbits.RB4

#define SEVENSEG_01_DIR	TRISBbits.RB7
#define SEVENSEG_02_DIR	TRISBbits.RB6
#define SEVENSEG_03_DIR	TRISBbits.RB5
#define SEVENSEG_04_DIR	TRISBbits.RB4

/* Buzzer definition */

#define BUZZER   PORTAbits.RA5
#define BUZZ_DIR TRISAbits.RA5
#define BUZ_ON 1
#define BUZ_OFF 0

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


/* LCD definitions */

/* LCD Register Selector 
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
*/
#define LCD_RS			PORTEbits.RE0 
#define LCD_RS_DIR		TRISEbits.RE0

#define LCD_RS_HIGH		1
#define LCD_RS_DATA		LCD_RS_HIGH

#define LCD_RS_LOW 		0
#define LCD_RS_CMD   	LCD_RS_LOW

#define LCD_ENABLE		PORTEbits.RE1 
#define LCD_ENABLE_DIR	TRISEbits.RE1 

#define LCD_ENABLED		1
#define LCD_DISABLED	0

#define LCD_DATA		PORTD
#define LCD_DATA_DIR	TRISD


/* Cooler definitions */
#define COOLER			PORTCbits.RC1
#define COOLER_DIR		TRISCbits.RC1

#define COOLER_ON		1
#define COOLER_OFF		0


#endif /* MCLAB2_H */
