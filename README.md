# Fan_control_system_using_AVR_micorcontroller
this project is implemented by software layered concept to abstract the microcontroller , hardware and application layers.
by using analog temperature sensor we convert the temperature to corresponding voltage based on this reading we use PWM driver to control the speed of our motor
# Video Simulation
https://user-images.githubusercontent.com/73777263/137817227-8896d618-06a1-45fb-bcac-b5997982257c.mp4
# Project Description
The aim of this project is to design a temperature-controlled fan using ATmega16<br />
microcontroller, in which the fan is automatically turned ON or OFF according to the <br />
temperature. Use ATmega16 Microcontroller with frequency 1Mhz.<br />
- the LM35 temperature sensor will give continuous analog output <br />
corresponding to the temperature sensed by it. This analog signal is given to the ADC, 
which converts the analog values to digital values.
-  In order to get the temperature from the sensed analog voltage, we need to perform some 
calculations in the programming for the microcontroller.<br />
- Once the calculations are done by the microcontroller according to the logic, the 
temperature is displayed on the LCD. <br />
- The microcontroller will continuously monitor the temperature and based on the 
temperature value, the microcontroller will drive the fan like that:<br/>
a. If the temperature is less than 30C turn off the fan.<br />
b. If the temperature is greater than or equal 30C turn on the fan with 25% of its 
maximum speed.<br />
c. If the temperature is greater than or equal 60C turn on the fan with 50% of its 
maximum speed.<br />
d. If the temperature is greater than or equal 90C turn on the fan with 75% of its 
maximum speed.<br />
e. If the temperature is greater than or equal 120C turn on the fan with 100% of its 
maximum speed.<br />
- The main principle of the circuit is to switch on/off the fan connected to DC motor based 
on temperature value. The DC-Motor rotates in clock-wise direction or stopped based on 
the fan state.<br />
# Hardware Components used in the application
1) AVR16 Microcontroller
2) LCD 2x16 LM016L
3) analog temperiture sensor LM35
4) DC Motor
5) Control chip which controls the motor L293D
# Software archtechiture drivers 
1) GPIO driver 
2) ADC driver impelmented by callback and interrupt design 
3) PWM driver
4) LCD driver
5) Temperature sensor driver
6) DC-Motor driver 
![layer](https://user-images.githubusercontent.com/73777263/137817860-9a776ec3-9b20-4303-b4b0-ff16dca3989c.PNG)





