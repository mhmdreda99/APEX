/*
 ============================================================================
 Name        : main.c
 Author      : the Great EVER Embedded Members
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 15/07/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : this code is to test ADC driver Specially with our Great EVER teammates
 ============================================================================
 */

// include nessecary libraries
#include <util/delay.h>
#include "../MCAL/ADC/ADC.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/Ext_Interrupt/Ext_Interrupt.h"
#include <avr/interrupt.h>


#define F_CPU	8000000UL
#define LDR		0

uint16 adcval = 0;
f32 adcValue = 0;

void updateADC(void) {
	ADC_getValue(&adcval);
	adcValue = ((adcval * 5) / 1024);
}

int main() {
	GPIO_init();
	LCD_init();

	ADC_init();
	ADC_callback(updateADC);
	ADC_setInterrupt(ADC_INTERRUPT_ENABLE);
	ENABLE_GLOBAL_INTERRUPT(); //sei();
	/*Configuration*/
	/*Initialization */


	_delay_ms(1000);
	LCD_writeCmd(lCD_CLEAR);
	LCD_writeTxt("Welcome");

	while (1) {
		//ADC_readVolt(LDR, &adcValue);
		ADC_startConversion(LDR);
		LCD_writeNumber(adcValue);
		_delay_ms(1000);
		LCD_writeCmd(lCD_CLEAR);
	}

	return 0;
}

