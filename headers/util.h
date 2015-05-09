/* ***************************************************************** */
/* File name:		 util.h              							 */
/* File description: Header file containing the function/methods     */
/*					 prototypes of util.c         					 */
/*                   Those delays were tested under the following:   */
/*					 PLLDIV = 1, FOSC = HSPLL_HS, CPUDIV = OSC1_PLL2 */
/*					 For the development kit McLab2					 */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    07mai2015										 */
/* ***************************************************************** */

#ifndef UTIL_H
#define UTIL_H

/* number of iterations to get 1 second
 * based on cyclic executive period
 */
#define UTIL_1S_ITERATION_NUM			10 

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


/* ************************************************ */
/* Method name: 	   util_initTimer1AsCounter  	*/
/* Method description: configure TIMER1             */
/*                     to be a 16b counter          */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_initTimer1AsCounter(void);


/* ************************************************ */
/* Method name: 	   util_resetTimer1Counter  	*/
/* Method description: reset the count of TIMER1    */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_resetTimer1Counter(void);


/* ************************************************ */
/* Method name: 	   util_startTimer1Counter  	*/
/* Method description: init the counting            */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_startTimer1Counter(void);


/* ************************************************ */
/* Method name: 	   util_stopTimer1Counter  		*/
/* Method description: stop the counting            */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_stopTimer1Counter(void);


/* ************************************************ */
/* Method name: 	   util_getTimer1Count  	    */
/* Method description: return the counting value    */
/*                     related to TIMER1 as counter */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
unsigned int util_getTimer1Count(void);


/* ************************************************ */
/* Method name: 	   util_configCyclicExecutive   */
/* Method description: configures the Cyclic Executive*/
/*                     timer interruption = 100ms   */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_configCyclicExecutive(void);


/* ************************************************ */
/* Method name: 	   util_resetCyclicExecutive    */
/* Method description: reset the TIMER0 high and low*/
/*                     values                       */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_resetCyclicExecutive(void);


/* ************************************************ */
/* Method name: 	   util_convertFromUi2Ascii     */
/* Method description: Convert from unsigned int to */
/*                     ASCII                        */
/* Input params:	   uiVal => number to be converted*/
/* Outpu params:	   *cStr => number converted	*/
/* ************************************************ */
void util_convertFromUi2Ascii(unsigned int uiVal, char *cStr);

#endif /* UTIL_H */
