/*
 * flame.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */
#include "flame.h"
#include "gpio.h"


void FlameSensor_init(void){

	GPIO_setupPinDirection( FLAME_PORT_ID, FLAME_PIN_ID, PIN_INPUT);

}
uint8 FlameSensor_getValue(void){
	if(GPIO_readPin(FLAME_PORT_ID, FLAME_PIN_ID)){
		return fire_on;
	}
	else{
		return fire_off;
	}

}

