/* ***************************************************************** */
/* File name:		 lcd.h							 			 	 */
/* File description: Header file containing the functions/methods    */
/*					 interfaces for handling the LCD hardware from	 */
/*					 the target 									 */
/* Author name:      dloubach										 */
/* Creation date:    16abr2015										 */
/* Revision date:    04mai2015										 */
/* ***************************************************************** */

#ifndef LCD_H
#define LCD_H

/* commands list */
#define CMD_INIT_LCD		0x0F
#define CMD_CLEAR			0x01
#define CMD_NO_CURSOR		0x0C
#define CMD_CURSOR2R		0x06 /* cursor to right */
#define CMD_NO_CUR_NO_BLINK 0x38 /* no cursor, no blink */




/* ************************************************ */
/* Method name: 	   lcd_initLcd	         		*/
/* Method description: Initialize the LCD function  */
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_initLcd(void);


/* ************************************************ */
/* Method name: 	   lcd_writeData				*/
/* Method description: Write data to be displayed   */
/* Input params:	   ucData => char to be writen  */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_writeData(unsigned char ucData);


/* ************************************************ */
/* Method name: 	   lcd_sendCommand				*/
/* Method description: Write command to LCD         */
/* Input params:	   ucCmd => command to be executed*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd);


/* ************************************************ */
/* Method name: 	   lcd_writeString				*/
/* Method description: Write string to be displayed */
/* Input params:	   ccBuffer => string to be     */
/*					   writen in LCD 				*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_writeString(const char *ccBuffer);


/* ************************************************ */
/* Method name: 	   lcd_setCursor         		*/
/* Method description: Set cursor line and column 	*/
/* Input params:	   cLine = LINE0..LINE1         */
/*					   cColumn = COLUMN0..MAX_COLUMN*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn);


/* ************************************************ */
/* Method name: 	   lcd_dummyText				*/
/* Method description: Write a dummy hard coded text*/
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_dummyText(void);

/* ************************************************ */
/* Method name: 	   lcd_WriteString2				*/
/* Method description: Write a string nicely 		*/
/* Input params:	   str => string to be written  */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_WriteString2(char str[]);

#endif /* LCD_H */