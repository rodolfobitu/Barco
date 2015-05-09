/* ***************************************************************** */
/* File name:		 cooler.c							 			 */
/* File description: File dedicated to the function implementation   */
/*                   related to the COOLER installed in the target   */
/* Author name:      dloubach										 */
/* Creation date:    04mai2015										 */
/* Revision date:    04mai2015										 */
/* ***************************************************************** */

#include "cooler.h"
#include "mclab2.h"


/* ************************************************ */
/* Method name: 	   cooler_initCooler			*/
/* Method description: initialize the cooler configs*/
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cooler_initCooler(void)
{
	COOLER = 0x0;
	COOLER_DIR = OUTPUT;
}



/* ************************************************ */
/* Method name: 	   cooler_turnOnOff			    */
/* Method description: initialize the cooler configs*/
/* Input params:	   cucOnOff => COOLER_ON        */
/*                              => COOLER_OFF       */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cooler_turnOnOff(const unsigned char cucOnOff)
{
	/* check input for turn on or turn off the cooler */
	if(COOLER_ON == cucOnOff)
		COOLER = COOLER_ON;
	else
	{
		if(COOLER_OFF == cucOnOff)
			COOLER = COOLER_OFF;
	}
}
