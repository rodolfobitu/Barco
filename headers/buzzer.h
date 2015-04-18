/* ***************************************************************** */
/* File name:		 buzzer.h            						 	*/
/* File description: File to handle buzzer							*/
/* Author name:      nois											 */
/* Creation date:    17abr2015										 */
/* Revision date:    17abr2015										 */
/* ***************************************************************** */

#ifndef BUZZER_H
#define BUZZER_H

/* ************************************************ */
/* Method name: 	   bz_init				   		*/
/* Method description: This method configures		*/
/*					   hardware pins to work with	*/
/*					   buzzer						*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_init(void);

/* ************************************************ */
/* Method name: 	   bz_set				   		*/
/* Method description: Turn buzzer on				 */
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_set(void);

/* ************************************************ */
/* Method name: 	   bz_clear				   		*/
/* Method description: Turn buzzer off				 */
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_clear(void);

/* ************************************************ */
/* Method name: 	   bz_buzzFor			   		*/
/* Method description: Turn buzzer on for a time	 */
/* Input params:	   iTime = time in ms			*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void bz_buzzFor(int iTime);

#endif /* BUZZER_H */
