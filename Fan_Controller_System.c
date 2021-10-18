/*
 ================================================================================================
 Name        : Fan_Controller_System.c
 Author      : Kareem Mohamed
 Description : Test the Fan Controller System
 Date        : 15/10/2021
 ================================================================================================
 */

#include"ADC.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"


int main(void)
{
   uint8 Temperature ;

   LCD_init();

   DcMotor_Init();

   ADC_ConfigType ADC_Configuration;

   ADC_Configuration.ref_volt = INTERNAL;

   ADC_Configuration.prescaler = Fcpu_By_8;

   ADC_init(& ADC_Configuration);



   while(1)
   {

	   Temperature = LM35_getTemperature();

	   if( Temperature >= 30 && Temperature < 60)
	   {
		   DcMotor_Rotate(CW,25);
		   LCD_moveCursor(0,3);
		   LCD_displayString("Fan is ON ");
	   }

	   else if(Temperature >= 60 && Temperature < 90)
	   {
		   DcMotor_Rotate(CW,50);
		   LCD_moveCursor(0,3);
		   LCD_displayString("Fan is ON ");
	   }

	   else if(Temperature >= 90 && Temperature < 120)
	   {
		   DcMotor_Rotate(CW,75);
		   LCD_moveCursor(0,3);
		   LCD_displayString("Fan is ON ");
	   }

	   else if(Temperature >= 120)
	   {
		   DcMotor_Rotate(CW,100);
		   LCD_moveCursor(0,3);
		   LCD_displayString("Fan is ON ");
	   }

	   else
	   {
		   DcMotor_Rotate(STOP,0);
		   LCD_moveCursor(0,3);
		   LCD_displayString("Fan is OFF");
	   }


	   LCD_moveCursor(1,3);

       LCD_displayString("Temp = ");

       /* Display the temperature value every time at same position */
       if(Temperature >= 100)
       {
    	   	LCD_intgerToString(Temperature);
    	   	LCD_displayCharacter('C');
       }

       else
       {
   			LCD_intgerToString(Temperature);
   			LCD_displayCharacter('C');
           	/* In case the digital value is two or one digits print space in the next digit place */
           	LCD_displayCharacter(' ');
       }
  }

}
