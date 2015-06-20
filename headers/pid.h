/* ***************************************************************** */
/* File name:		 pid.h            								 */
/* File description: Header file containing the function/methods     */
/*					 prototypes of pid.c 	      					 */
/* Author name:      nois											 */
/* Creation date:    06jun2015										 */
/* Revision date:    06jun2015										 */
/* ***************************************************************** */

#ifndef PID_H
#define PID_H

typedef struct PID {
	double dP, dI, dD;
	double dErrorSum;
	double dLast;
} PID;

/* ************************************************ */
/* Method name: 	   pid_init				   		*/
/* Method description: Create a PID instance		*/
/* Input params:	   dP = proportinal gain	 	*/
/*					   dI = integrative gain	    */
/*					   dD = derivative gain			*/
/* Outpu params:	   PID instance					*/
/* ************************************************ */
PID pid_init(double dP, double dI, double dD);

/* ************************************************ */
/* Method name: 	   pid_update	         		*/
/* Method description: Update the PID state and     */
/* 					   return the control signal    */
/* Input params:	   pid = the initialized PID	*/
/* 					   dRef = reference value		*/
/* 					   dSensorValue = curr. sample	*/
/* Outpu params:	   control signal				*/
/* ************************************************ */
double pid_update(PID *pid, double dRef, double dSensorValue);

#endif /* PID_H */