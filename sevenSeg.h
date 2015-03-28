/* ***************************************************************** */
/* File name:		 sevenSeg.h            							 */
/* File description: Header file containing the function/methods     */
/*					 prototypes of sevenSeg.c      					 */
/* Author name:      nois											 */
/* Creation date:    27mar2015										 */
/* Revision date:    27mar2015										 */
/* ***************************************************************** */

#ifndef SEVENSEG_H
#define SEVENSEG_H

typedef enum {
	SEVENSEG_CLEAR = -1,
	SEVENSEG_0 = 0,
	SEVENSEG_1,
	SEVENSEG_2,
	SEVENSEG_3,
	SEVENSEG_4,
	SEVENSEG_5,
	SEVENSEG_6,
	SEVENSEG_7,
	SEVENSEG_8,
	SEVENSEG_9,
	SEVENSEG_A,
	SEVENSEG_B,
	SEVENSEG_C,
	SEVENSEG_D,
	SEVENSEG_E,
	SEVENSEG_F
} sevenseg_value_e;

/* ************************************************ */
/* Method name: 	   sevenseg_init		   		*/
/* Method description: This method configures		*/
/*					   hardware pins to work with	*/
/*					   seven segment display		*/
/* Input params:	   n/a							*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void sevenseg_init(void);

/* ************************************************ */
/* Method name: 	   sevenseg_set         		*/
/* Method description: set the desired seven segment*/
/*					   to a value					*/
/* Input params:	   cSSNum = which display {1..4}*/
/*					   eValue = which value 		*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void sevenseg_set(char cSSNum, sevenseg_value_e eValue);


/* ************************************************ */
/* Method name: 	   sevenseg_setWithInt     		*/
/* Method description: set 7seg with an int			*/
/*					 								*/
/* Input params:	   iValue = int {0..9999}		*/
/*					   								*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void sevenseg_setWithInt (int iValue);

#endif /* SEVENSEG_H */
