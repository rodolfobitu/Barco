/* ***************************************************************** */
/* File name:		 util.c                  						 */
/* File description: This file has a couple of useful functions to   */
/*					 make programming more productive			     */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    09jan2015										 */
/* ***************************************************************** */

#include "util.h"
#include "mclab2.h"

/* ************************************************ */
/* Method name: 	   util_genDelay1MS      		*/
/* Method description: generates ~ 1ms delay        */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay1MS(void)
{
	char i;
	for(i=0; i<69; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}


/* ************************************************ */
/* Method name: 	   util_genDelay10MS      		*/
/* Method description: generates ~ 10ms delay       */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay10MS(void)
{
	char i;
	for(i=0; i<9; i++)
		util_genDelay1MS();
	for(i=0; i<59; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}


/* ************************************************ */
/* Method name: 	   util_genDelay100MS      		*/
/* Method description: generates ~ 100ms delay      */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay100MS(void)
{
	char i;
	for(i=0; i<9; i++)
		util_genDelay10MS();
	for(i=0; i<9; i++)
		util_genDelay1MS();
	for(i=0; i<49; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}


/* ************************************************ */
/* Method name: 	   util_genDelay500MS      		*/
/* Method description: generates ~ 500ms delay      */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void util_genDelay500MS(void)
{
	char i;
	for(i=0; i<4; i++)
		util_genDelay100MS();
	for(i=0; i<9; i++)
		util_genDelay10MS();
	for(i=0; i<9; i++)
		util_genDelay1MS();
	for(i=0; i<44; i++)
	{
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
		Nop();
	}
}
