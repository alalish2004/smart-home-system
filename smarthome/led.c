/*
 * led.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */

#include "common_macros.h"
#include <avr/io.h>
#include "gpio.h"
#include "led.h"


void LEDS_init(void){
	               /* FIRST SET ALL PINS TO OUTPUT */
	 GPIO_setupPinDirection(LED_PORT_ID, LED_RED_PIN, PIN_OUTPUT);
	 GPIO_setupPinDirection(LED_PORT_ID, LED_GREEN_PIN, PIN_OUTPUT);
	 GPIO_setupPinDirection(LED_PORT_ID, LED_BLUE_PIN, PIN_OUTPUT);
	                  /* TURN OFF ALL THE LEDS */
	 GPIO_writePin(LED_PORT_ID, LED_RED_PIN, led_off);
	 GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN, led_off);
	 GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN, led_off);
}
void LED_on(LED_ID id){
	GPIO_writePin(LED_PORT_ID, id, led_on);
}
void LED_off(LED_ID id){
	GPIO_writePin(LED_PORT_ID, id, led_off);

}





