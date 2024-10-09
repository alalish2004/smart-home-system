/*
 * buzzer.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */
#include "gpio.h"
#include "buzzer.h"


void Buzzer_init(void){
	GPIO_setupPinDirection( BUZZER_port, BUZZER_pin, PIN_OUTPUT);
	GPIO_writePin( BUZZER_port, BUZZER_pin, LOGIC_LOW);
}
void Buzzer_on(void){
	GPIO_writePin( BUZZER_port, BUZZER_pin, LOGIC_HIGH);
}
void Buzzer_off(void){
	GPIO_writePin( BUZZER_port, BUZZER_pin, LOGIC_LOW);
}
