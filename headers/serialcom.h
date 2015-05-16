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
/* Method name: 	   sc_read						*/
/* Method description: Read a single char from		*/
/*						RCREG, if available			*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_read(void);

/* ************************************************ */
/* Method name: 	   sc_send		   		*/
/* Method description: Sends a char from TXBuffer using */
/* 						the serial communication.	*/
/* Input params:	   char* cBuf					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_send(void);

/* ************************************************ */
/* Method name: 	   sc_readLine		   		*/
/* Method description: Write the next received line */
/*						into input buffer. If no	*/
/*						has been received, the is	*/
/*						emptied						*/
/* Input params:	   char cBuf[]					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_readLine(char cBuf[]);


/* ************************************************ */
/* Method name: 	   sc_sendLine					*/
/* Method description: Populate TXBuffer with a cBuf*/
/*						to be send					*/
/* Input params:	   char* cBuf					*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void sc_sendLine(char* cBuf);


#endif /* SERIALCOM_H */
