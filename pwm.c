/******************************************************************************
 *
 * Module: TIMER0 PWM Mode
 *
 * File Name: pwm.c
 *
 * Description: Source file for Timer0 PWM Mode
 *
 * Author: Kareem Mohamed
 *
 *******************************************************************************/

#include "common_macros.h" /* To use the macros like SET_BIT */
#include "pwm.h"
#include "gpio.h"
#include "avr/io.h" /* To use Timer0 Registers*/

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * The function responsible for trigger the Timer0 with the PWM Mode.
 * Setup the PWM mode with Non-Inverting.
 * Setup the prescaler with F_CPU/8.
 * Setup the compare value based on the required input duty cycle
 * Setup the direction for OC0 as output pin through the GPIO driver.
 * The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Configure timer0 control register (TCCR0)
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	*/

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

	TCNT0 = 0;

	if(duty_cycle == 100)
		OCR0 = 255 * ( (float32)(duty_cycle)/100 ); /* The compare value according to duty cycle */

	else
		OCR0 = 256 * ( (float32)(duty_cycle)/100 ); /* The compare value according to duty cycle */

	GPIO_setupPinDirection(PWM_SIGNAL_PORT,PWM_SIGNAL_PIN,PIN_OUTPUT); //set PB3/OC0 as output pin

}
