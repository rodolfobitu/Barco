/* ***************************************************************** */
/* File name:		 cmdMachine.c           					 	*/
/* File description: File to interpret the commands from serial		*/
/* Author name:      nois											 */
/* Creation date:    17abr2015										 */
/* Revision date:    17abr2015										 */
/* ***************************************************************** */

#include "cmdMachine.h"
#include "ledswi.h"
#include "buzzer.h"

void cm_ledCmd(char cCmd[]);
void cm_buzzerCmd(char cCmd[]);

/* ************************************************ */
/* Method name: 	   cm_interpretCmd		   		*/
/* Method description: Interpret the command		*/
/* Input params:	   cCmd[] = command				*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cm_interpretCmd(char cCmd[]){
	if (cCmd[0] == 'L'){
		cm_ledCmd(cCmd);
	} else if (cCmd[0] == 'S'){
		//Switch
	} else if (cCmd[0] == 'B'){
		cm_buzzerCmd(cCmd);
	} else {
		//invalid
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