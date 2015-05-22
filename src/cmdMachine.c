/* ***************************************************************** */
/* File name:		 cmdMachine.c           					 	*/
/* File description: File to interpret the commands from serial		*/
/* Author name:      nois											 */
/* Creation date:    17abr2015										 */
/* Revision date:    17abr2015										 */
/* ***************************************************************** */

#include "es670_pp.h"
#include "cmdMachine.h"
#include "ledswi.h"
#include "buzzer.h"
#include "lcd.h"
#include "serialcom.h"
#include "util.h"
#include <ctype.h>

static int speed;
static char showSpeed = 0;

void cm_ledCmd(char cCmd[]);
void cm_buzzerCmd(char cCmd[]);
void cm_lcdCmd(char cCmd[]);


/* ************************************************ */
/* Method name: 	   cm_interpretCmd		   		*/
/* Method description: Interpret the command		*/
/* Input params:	   cCmd[] = command				*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cm_interpretCmd(char cCmd[]){	
	if (cCmd[0] == 'L'){
		if (cCmd[2] == 'D' && cCmd[1] == 'C'){
			char akn[4] = "AKN";
			showSpeed = FALSE;
			sc_sendLine(akn);
			cm_lcdCmd(cCmd);
		}else{
			char akn[4] = "AKN";
			sc_sendLine(akn);
			cm_ledCmd(cCmd);
		}
	} else if (cCmd[0] == 'S'){
		//Switch
		if (cCmd[1] == 'P' && cCmd[2] == 'D'){
			char text[20];			
			showSpeed = TRUE;
			util_convertFromUi2Ascii(speed, text);
			sc_sendLine(text);
		}
	} else if (cCmd[0] == 'B'){
		char akn[4] = "AKN";
		sc_sendLine(akn);
		cm_buzzerCmd(cCmd);
	} else {
		if (cCmd[0] != '\0'){
			char nakn[10] = "NOTAKN";
			sc_sendLine(nakn);
		}
		//invalid
	}

	if (showSpeed){
		char text[20];
		/* Show the result in the LCD display */
		util_convertFromUi2Ascii(speed, text);
		lcd_WriteString2(text);
		
		
	}

}

/* ************************************************ */
/* Method name: 	   cm_ledCmd			   		*/
/* Method description: command led 1-4 to set or clear*/
/* Input params:	   cCmd[] = command (L[CS][1-4])	*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cm_ledCmd(char cCmd[]){
	if (cCmd[1] == 'C'){
		if ('1' <= cCmd[2] && cCmd[2] <= '4'){
			char cLedNum = cCmd[2] - '0';
			ledswi_clearLed(cLedNum);
		}
		else {
			//invalid
		}
	} else if (cCmd[1] == 'S'){
		if ('1' <= cCmd[2] && cCmd[2] <= '4'){
			char cLedNum = cCmd[2] - '0';
			ledswi_setLed(cLedNum);
		}
		else {
			//invalid
		}
	}

}

/* ************************************************ */
/* Method name: 	   cm_buzzerCmd			   		*/
/* Method description: command buzzer to buzz      */
/* Input params:	   cCmd[] = command (Bxxxx)	*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cm_buzzerCmd(char cCmd[]){
	int time = 0;
	int i;
	for(i=1;i<5;i++){
		if ('0' <= cCmd[i] && cCmd[i] <= '9'){
			time = 10*time + cCmd[i] - '0';
		}else{
			return;
		}
	}

	bz_buzzFor(time);

}

/* ************************************************ */
/* Method name: 	   cm_lcdCmd			   		*/
/* Method description: command buzzer to buzz      */
/* Input params:	   cCmd[] = command (LCDxxxx*)	*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cm_lcdCmd(char cCmd[]){
	int j=3;
	char str[50];
		
	
	while(cCmd[j] != '\0'){
		str[j-3] = cCmd[j];
		j++;
	}
	str[j-3]='\0';
	lcd_WriteString2(str);
	
}

/* ************************************************ */
/* Method name: 	   cm_setSpeed			   		*/
/* Method description: Set the speed static int      */
/* Input params:	   int iValue							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cm_setSpeed(int iValue){
	
	speed = iValue;
}


