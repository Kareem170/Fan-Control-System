 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Kareem Mohamed
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = (Config_Ptr -> ref_volt) To Use A Certain Reference Voltage Defined By Application
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (ADMUX & 0X00) | ( (Config_Ptr -> ref_volt) << 6) ;

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = (Config_Ptr -> prescaler) To Use A Certain Prescaler Defined By Application
	 */
	ADCSRA = (ADCSRA & 0X00) | (1<<ADEN) | ( (Config_Ptr -> prescaler) & 0X07);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	 /* Input channel number must be from 0 --> 7
	  * Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel
	  * Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX = (ADMUX & 0XE0) | (channel_num & 0X07);

	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */

	while( BIT_IS_CLEAR(ADCSRA,ADIF) );  /* Wait Until The Conversion Completes ( ADIF = 1 ) */

	SET_BIT(ADCSRA,ADIF);  /* Clear The ADIF Flag By Writing Logical '1' */

	return ADC ;
}
