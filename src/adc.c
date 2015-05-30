/* ***************************************************************** */
/* File name:		 adc.c							 			 	 */
/* File description: File dedicated to the function implementation   */
/*                   related to ADC module from the uC target        */
/* Author name:      dloubach										 */
/* Creation date:    21mai2015										 */
/* Revision date:    22mai2015										 */
/* ***************************************************************** */

#include "adc.h"
#include "mclab2.h"

/* ************************************************ */
/* Method name: 	   adc_initAdc					*/
/* Method description: initialize the ADC configs   */
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void adc_initAdc(void)
{
	/* let's select the CHANNEL 0 */
	ADCON0bits.CHS = 0;

	/* config the reference voltage */
	ADCON1bits.VCFG1 = 0; //VSS
	ADCON1bits.VCFG0 = 0; //VDD
	/* AD port configuration, for AN0 going to ANALOG INPUT */
	ADCON1bits.PCFG = 0b1110;

	/* right justfied */
	ADCON2bits.ADFM = 1;
	/* acquistion time */
	ADCON2bits.ACQT = 0b101;  // 12 TAD

	/* converstion clock */
	ADCON2bits.ADCS = 0b110;  // 64 TOSC

	/* ADC module ON */
	ADCON0bits.ADON = 1;
}



/* ************************************************ */
/* Method name: 	   adc_isAdcDone				*/
/* Method description: verify if the AD convertion  */
/*                     is done                      */
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
int adc_isAdcDone(void)
{
	unsigned char ucAdcStatus;
	int iReturn;

	/* get the ADC convertion status */
	ucAdcStatus = ADCON0bits.GO_DONE;

	/* check it */
	if(ucAdcStatus)
		iReturn = ADC_CONVERTION_PROCESSING;
	else
		iReturn = ADC_CONVERTION_DONE;

	/* return the result */
	return (iReturn);
}



/* ************************************************ */
/* Method name: 	   adc_startConvertion			*/
/* Method description: start the AD convertion      */
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void adc_startConvertion(void)
{
	ADCON0bits.GO_DONE = 1;
}



/* ************************************************ */
/* Method name: 	   adc_getValue					*/
/* Method description: return the value after the   */
/*                     AD convertion is done		*/
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
unsigned int adc_getValue(void)
{
	unsigned int uiAdcLowValue;
	unsigned int uiAdcValue;

	/* return the MSB + LSB parts */
	uiAdcLowValue = ADRESL;
	uiAdcValue = (((unsigned int)ADRESH & 0x03) << 8) + uiAdcLowValue;

	return(uiAdcValue);
}
