/* ***************************************************************** */
/* File name:		 buzzer.h c          						 	*/
/* File description: File to handle buzzer							*/
/* Author name:      nois											 */
/* Creation date:    17abr2015										 */
/* Revision date:    17abr2015										 */
/* ***************************************************************** */

#include "buzzer.h"
#include "util.h"
#include "mclab2.h"

/* ************************************************ */
/* Method name: 	   bz_init				   		*/
/* Method description: This method configures		*/
/*					   hardware pins to work with	*/
/*					   buzzer						*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_init(void){
	BUZZ_DIR = OUTPUT;
}

/* ************************************************ */
/* Method name: 	   bz_set				   		*/
/* Method description: Turn buzzer on				 */
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_set(void){
	BUZZER = BUZ_ON;
}

/* ************************************************ */
/* Method name: 	   bz_clear				   		*/
/* Method description: Turn buzzer off				 */
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_clear(void){
	BUZZER = BUZ_OFF;
}

/* ************************************************ */
/* Method name: 	   bz_buzzFor			   		*/
/* Method description: Turn buzzer on for a time	 */
/* Input params:	   iTime = time in ms			*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_buzzFor(int iTime){
	
	
	while (iTime > 0){
		bz_set();
		util_genDelay1MS();
		bz_clear();
		util_genDelay1MS();
		iTime -= 2;
	}
	
	
	
}

