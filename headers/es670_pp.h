/* ***************************************************************** */
/* File name:		 es670_pp.h							 			 */
/* File description: Header file containing a couple of defintions   */
/*					 used for configuring the uC					 */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    22mai2015										 */
/* ***************************************************************** */

#ifndef ES670_H
#define ES670_H

/* general constants */
#define TRUE  		1
#define FALSE 		0

#define CLEAN_DATA	0x00

typedef enum {
	/* LCD stay static */
	DISPLAY_STATIC,	
	/* LCD monitoring control values */
	DISPLAY_MONIT	
} display_state_e;

#endif /* ES670_H */
