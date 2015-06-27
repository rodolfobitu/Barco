/* ***************************************************************** */
/* File name:		 lcd.c							 			     */
/* File description: File dedicated to the function implementation   */
/*                   related to the LCD HARDWARE based on the KS006U */
/*					 controller										 */
/* Author name:      dloubach										 */
/* Creation date:    16abr2015										 */
/* Revision date:    06mai2015										 */
/* ***************************************************************** */

#include "lcd.h"
#include "mclab2.h"
#include "util.h"

/* line and columns */
#define LINE0		0
#define COLUMN0		0

#define L0C0_BASE	0x80 /* line 0, column 0 */
#define L1C0_BASE	0xC0 /* line 1, column 0 */
#define MAX_COLUMN  15


/* ************************************************ */
/* Method name: 	   lcd_initLcd	         		*/
/* Method description: Initialize the LCD function  */
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_initLcd(void)
{
	/* ports configured as outputs */
	LCD_RS_DIR     = OUTPUT;
	LCD_ENABLE_DIR = OUTPUT;
	LCD_DATA_DIR   = OUTPUT;

	// turn-on LCD, with no cursor and no blink
	lcd_sendCommand(CMD_NO_CUR_NO_BLINK);

	// init LCD	
	lcd_sendCommand(CMD_INIT_LCD);
	
	// clear LCD
	lcd_sendCommand(CMD_CLEAR);
	
	// LCD with no cursor
	lcd_sendCommand(CMD_NO_CURSOR);

	// cursor shift to right
	lcd_sendCommand(CMD_CURSOR2R);

}



/* ************************************************ */
/* Method name: 	   lcd_write2Lcd         		*/
/* Method description: Send command or data to LCD  */
/* Input params:	   ucBuffer => char to be send  */
/*                   cDataType => command LCD_RS_CMD*/
/*                     or data LCD_RS_DATA          &/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_write2Lcd(unsigned char ucBuffer,  unsigned char cDataType)
{
	/* writing data or command */
	if(LCD_RS_CMD == cDataType)
		/* will send a command */
		LCD_RS = LCD_RS_CMD;
	else
		/* will send data */
		LCD_RS = LCD_RS_DATA;
		
	/* write in the LCD bus */
	LCD_DATA = ucBuffer;
		
	/* enable, delay, disable LCD */
	/* this generates a pulse in the enable pin */
	LCD_ENABLE = LCD_ENABLED;
	LCD_ENABLE = LCD_DISABLED;	
	util_genDelay1MS();
	util_genDelay1MS();
}

/* ************************************************ */
/* Method name: 	   lcd_writeData				*/
/* Method description: Write data to be displayed   */
/* Input params:	   ucData => char to be writen  */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_writeData(unsigned char ucData) {
	/* just a relay to send data */
	lcd_write2Lcd(ucData, LCD_RS_DATA);
}



/* ************************************************ */
/* Method name: 	   lcd_sendCommand				*/
/* Method description: Write command to LCD         */
/* Input params:	   ucCmd => command to be executed*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd) {
	/* just a relay to send command */
	lcd_write2Lcd(ucCmd, LCD_RS_CMD);
}

/* ************************************************ */
/* Method name: 	   lcd_setCursor         		*/
/* Method description: Set cursor line and column 	*/
/* Input params:	   cLine = LINE0..LINE1         */
/*					   cColumn = COLUMN0..MAX_COLUMN*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn)
{
	char cCommand;
	
	if(LINE0 == cLine)
		/* line 0 */
		cCommand = L0C0_BASE;
	else
		/* line 1 */
		cCommand = L1C0_BASE;
		
	/* maximum MAX_COLUMN columns */
	cCommand += (cColumn & MAX_COLUMN);
	
	// send the command to set the curor
	lcd_sendCommand(cCommand);
}



/* ************************************************ */
/* Method name: 	   lcd_WriteString				*/
/* Method description: Write string to be displayed */
/* Input params:	   ccBuffer => string to be     */
/*					   writen in LCD 				*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_writeString(const char *ccBuffer)
{
	while(*ccBuffer)
	{
		lcd_writeData(*ccBuffer++);
	};
}



/* ************************************************ */
/* Method name: 	   lcd_dummyText				*/
/* Method description: Write a dummy hard coded text*/
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_dummyText(void)
{
	const char cDummyText[] = "*** ES670 ***";
	const char cDummyText2[] = "Prj Sis Embarcad";
	
	// clear LCD
	lcd_sendCommand(CMD_CLEAR);
					
	// set the cursor line 0, column 1
	lcd_setCursor(0,1);
	lcd_writeString(cDummyText);

	// set the cursor line 1, column 0
	lcd_setCursor(1,0);
	lcd_writeString(cDummyText2);	
}

/* ************************************************ */
/* Method name: 	   lcd_WriteString2				*/
/* Method description: Write a string nicely 		*/
/* Input params:	   str => string to be written  */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void lcd_WriteString2(char str[]) {
	int i=0;
	char cursorLine = 0;

	// clear LCD
	lcd_sendCommand(CMD_CLEAR);	
	util_genDelay10MS();		
	// set the cursor line 0, column 1
	lcd_setCursor(0,0);
	
	while (str[i] != '\0'){
		if (str[i] == '\n' && cursorLine == 0){
			lcd_setCursor(1,0);
			cursorLine = 1;
		} else {
			lcd_write2Lcd(str[i], LCD_RS_DATA);
		}
		
		i++;
		if (i == 16 && cursorLine == 0){
			cursorLine = 1;
			lcd_setCursor(1,0);
		}
	}
}