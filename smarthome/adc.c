/*
 * adc.c
 *
 *  Created on: Sep 28, 2024
 *      Author: ALI
 */

#include "common_macros.h"
#include <avr/io.h>
#include "adc.h"
#include "gpio.h"

void ADC_init(void){
	// to make it use 2.56v internal refrence voltage
	SET_BIT(ADC_muxRegister, REFS0);
	SET_BIT(ADC_muxRegister, REFS1);


	SET_BIT(ADC_controlRegister, 7);//ADC ENABLE
	CLEAR_BIT(ADC_controlRegister , 3);//DISABLE ADC INTERUPT
	//SET PRESCALE TO 128
	SET_BIT(ADC_controlRegister, 2);
	SET_BIT(ADC_controlRegister, 1);
	SET_BIT(ADC_controlRegister, 0);
}

uint16 ADC_readChannel(uint8 ch_num){
	ch_num &= 0x07; // Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; // Clear first 5 bits in the ADMUX
	ADMUX = ADMUX | ch_num; // Choose the correct channel
	SET_BIT(ADCSRA,ADSC); // Start conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); // Wait for conversion
	SET_BIT(ADCSRA,ADIF); // Clear ADIF by write '1' to it
	return ADC;


}




