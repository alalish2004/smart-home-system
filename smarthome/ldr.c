/*
 * ldr.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */

#include "common_macros.h"
#include <avr/io.h>
#include "adc.h"
#include "gpio.h"
#include "ldr.h"


uint16 LDR_getLightIntensity(void){
	uint16 temp_value = 0;

	uint16 adc_value = 0;

	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	temp_value = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));
	//temp_value = ((temp_value)/1023)*100;
	return temp_value;
}
