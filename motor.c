/******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.c
 *
 * Description: Source file for the DC Motor driver
 *
 * Author: Kareem Mohamed
 *
 *******************************************************************************/

#include "common_macros.h" /* To use the macros like SET_BIT */
#include "motor.h"
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_DRIVER_PORT,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_DRIVER_PORT,PIN1_ID,PIN_OUTPUT);

    /*Stop at the DC-Motor at the beginning through the GPIO driver*/
	GPIO_writePin(MOTOR_DRIVER_PORT,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_DRIVER_PORT,PIN1_ID,LOGIC_LOW);
}

/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the motor state.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value*/
	GPIO_writePort(PORTB_ID,state);

	/*decimal value for the required motor speed, it should be from 0 --> 100*/
	PWM_Timer0_Start(speed);


}


