/* ***************************************************************** */
/* File name:		 cooler.h							 			 */
/* File description: Header file containing the functions/methods    */
/*					 interfaces for handling the COOLER hardware from*/
/*					 the target 									 */
/* Author name:      dloubach										 */
/* Creation date:    04mai2015										 */
/* Revision date:    04mai2015										 */
/* ***************************************************************** */

#ifndef COOLER_H
#define COOLER_H

#define COOLER_BLADES_NUM		7

/* ************************************************ */
/* Method name: 	   cooler_initCooler			*/
/* Method description: initialize the cooler configs*/
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cooler_initCooler(void);


/* ************************************************ */
/* Method name: 	   cooler_turnOnOff			    */
/* Method description: initialize the cooler configs*/
/* Input params:	   cucOnOff => COOLER_ON        */
/*                              => COOLER_OFF       */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cooler_turnOnOff(const unsigned char cucOnOff);


#endif /* COOLER_H */