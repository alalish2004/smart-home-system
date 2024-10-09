/*
 * pwm.c
 *
 *  Created on: Oct 4, 2024
 *      Author: ALI
 */
#include <avr/io.h>
#include "pwm.h"
#include "gpio.h"
#include "common_macros.h"


void PWM_Timer0_Start(uint8 duty_cycle){

	duty_cycle = (uint8)((uint16)((duty_cycle)*255)/100);

	timerCounterregister = 0; //Set Timer Initial value

	outputCompareRegister = duty_cycle; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin to generate the waveform

	timerCounterControlRegister = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS02) | (1<<CS00);

}

