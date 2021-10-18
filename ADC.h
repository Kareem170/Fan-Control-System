/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Kareem Mohamed
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   (2.56f)

/*******************************************************************************
 *                             Static Configurations                            *
 *******************************************************************************/

/* ADC_ReferenceVolatge Contains The Possible Reference Voltage For ADC Driver .
 * The Values Represent The (REFS1 , REFS0) bits (Reference Voltage Selection Bits) In (ADMUX) Register. */
typedef enum
{
	AVCC = 0X01 , INTERNAL  = 0X03 , AREF = 0X00
}ADC_ReferenceVolatge;


/* ADC_Prescaler Contains The division factors which the CPU Frequency is divided by it
   and the result is the input frequency for ADC Driver .
 * The Values Represent The (ADPS2 , ADPS1 , ADPS 0) bits In (ADCSRA) Register */
typedef enum
{
	Fcpu_By_2 = 0X00 , Fcpu_By_4  = 0X02 , Fcpu_By_8 = 0X03 , Fcpu_By_16 = 0X04 ,
	Fcpu_By_32 = 0X05 , Fcpu_By_64 = 0X06 , Fcpu_By_128 = 0X07
}ADC_Prescaler;

/* This Structure Contains The Configuration For Reference Voltage and Prescaler For ADC Driver */
typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver Using
   pointer to the configuration structure with type ADC_ConfigType.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);
#endif /* ADC_H_ */
