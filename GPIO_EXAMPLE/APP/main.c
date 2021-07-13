 /*============================================================================
 Name        : StdMacros.h
 Author      : Mohamed Reda
 Layer		 : Application layer
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 08/07/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : this is a simple applicaion on session 1 to loop on blinking leds to ease how to use
  GPIO Driver

 ============================================================================
*/

#include "../MCAL/GPIO/GPIO.h"
#include <util/delay.h>

void main(void)

	// Intialize GPIO
	GPIO_init();
    // Set Pins Directions
	GPIO_setPinDirection( GPIO_PORTB ,4,GPIO_HIGH);
	GPIO_setPinDirection( GPIO_PORTB ,5,GPIO_HIGH);
	GPIO_setPinDirection( GPIO_PORTB ,6,GPIO_HIGH);
	GPIO_setPinDirection( GPIO_PORTB ,7,GPIO_HIGH);
	GPIO_setPinDirection( GPIO_PORTA ,4,GPIO_HIGH); // SET BUZZER
	while(1)
	{
		uint8 i ;
		for (i=0 ;i <= MAX_PIN_NUMBER;i++)
		{
			_delay_ms(500);
			GPIO_writePin(GPIO_PORTA,4,GPIO_LOW); // Turn off BUZZER
			GPIO_writePin(GPIO_PORTB,i,GPIO_HIGH); // loop on LED pins
			_delay_ms(500);
			GPIO_writePin(GPIO_PORTB,i,GPIO_LOW); // loop on LED pins

		}
		GPIO_writePin(GPIO_PORTA,4,GPIO_HIGH); // Turn on BUZZER after LEDs turn off


	}
}
