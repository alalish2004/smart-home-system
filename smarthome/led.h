/*
 * led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */

#ifndef LED_H_
#define LED_H_

#include"std_types.h"


#define LED_PORT_ID      PORTB_ID
#define LED_RED_PIN      PIN5_ID
#define LED_GREEN_PIN    PIN6_ID
#define LED_BLUE_PIN     PIN7_ID
#define led_on           1  //set to one to use positive logic and to 0 to use negative logic


#if led_on
#define led_off 0
#else
#define led_off 1
#endif

typedef unsigned char    LED_ID;


void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);





#endif /* LED_H_ */
