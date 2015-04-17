/* ***************************************************************** */
/* File name:		 util.h              							 */
/* File description: Header file containing the function/methods     */
/*					 prototypes of util.c         					 */
/*                   Those delays were tested under the following:   */
/*					 PLLDIV = 1, FOSC = XTPLL_XT, CPUDIV = OSC1_PLL2 */
/*					 For the development kit McLab2					 */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    29jan2015										 */
/* ***************************************************************** */

#ifndef UTIL_H
#define UTIL_H

/* ************************************************ */
/* Method name: 	   util_genDelay1MS      		*/
/* Method description: generates ~ 1ms delay        */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay1MS(void);


/* ************************************************ */
/* Method name: 	   util_genDelay10MS      		*/
/* Method description: generates ~ 10ms delay       */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay10MS(void);


/* ************************************************ */
/* Method name: 	   util_genDelay100MS      		*/
/* Method description: generates ~ 100ms delay      */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay100MS(void);


/* ************************************************ */
/* Method name: 	   util_genDelay500MS      		*/
/* Method description: generates ~ 500ms delay      */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay500MS(void);


#endif /* UTIL_H */
