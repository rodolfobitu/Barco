/* ***************************************************************** */
/* File name:		 pid.c            								 */
/* File description: Implement a PID controller						 */
/* Author name:      nois											 */
/* Creation date:    06jun2015										 */
/* Revision date:    06jun2015										 */
/* ***************************************************************** */

#include "pid.h"

/* ************************************************ */
/* Method name: 	   pid_init				   		*/
/* Method description: Create a PID instance		*/
/* Input params:	   dP = proportinal gain	 	*/
/*					   dI = integrative gain	    */
/*					   dD = derivative gain			*/
/* Outpu params:	   PID instance					*/
/* ************************************************ */
PID pid_init(double dP, double dI, double dD) {
	PID pid = {
		dP,
		dI,
		dD,
		0,
		0
	};
	return pid;
}

/* ************************************************ */
/* Method name: 	   pid_update	         		*/
/* Method description: Update the PID state and     */
/* 					   return the control signal    */
/* Input params:	   pid = the initialized PID	*/
/* 					   dRef = reference value		*/
/* 					   dSensorValue = curr. sample	*/
/* Outpu params:	   control signal				*/
/* ************************************************ */
double pid_update(PID *pid, double dRef, double dSensorValue) {
	double dError, dDiff, dErrorSum;
	
	/* Update the PID state */
	dError = dRef - dSensorValue;
	dErrorSum = (pid->dErrorSum += dError);
	dDiff = dSensorValue - pid->dLast;
	pid->dLast = dSensorValue;
	
	return (pid->dP * dError) + (pid->dI * dErrorSum) + (pid->dD * dDiff);
}