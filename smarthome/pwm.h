/*
 * pwm.h
 *
 *  Created on: Oct 3, 2024
 *      Author: ALI
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

#define timerCounterControlRegister TCCR0
#define timerCounterregister TCNT0
#define outputCompareRegister OCR0
#define timerInterruptMaskRegister TIMSK

void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
