/* ***************************************************************** */
/* File name:		 serialcom.h            						 */
/* File description: Header file containing the function/methods     */
/*					 prototypes of serialcom.c       			     */
/* Author name:      nois										 */
/* Creation date:    10abr2015										 */
/* Revision date:    10abr2015										 */
/* ***************************************************************** */

#ifndef SERIALCOM_H
#define SERIALCOM_H

/* ************************************************ */
/* Method name: 	   sc_init		   		*/
/* Method description: This method configures		*/
/*					   hardware pins to work with	*/
/*					   serial communication		*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_init(void);

/* ************************************************ */
/* Method name: 	   sc_start		   		*/
/* Method description: Sends '$' until we receive 'A' */
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_start(void);


/* ************************************************ */
/* Method name: 	   sc_sendBuffer		   		*/
/* Method description: Sends buffer using the serial*/
/* 						communication.				*/
/* Input params:	   char cBuf[]					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_sendBuffer(char cBuf[]);

/* ************************************************ */
/* Method name: 	   sc_receiveBuffer		   		*/
/* Method description: Receive a buffer using serial*/
/* 						communication.				*/
/* Input params:	   char cBuf[]					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_receiveBuffer(char cBuf[]);


#endif /* SERIALCOM_H */
