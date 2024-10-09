/*
 * dcmotor.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */
#include "dcmotor.h"
#include "common_macros.h"
#include <avr/io.h>
#include "adc.h"
#include "gpio.h"


void DcMotor_Init(void){
	/* set up motor pins as output pins */
	GPIO_setupPinDirection(motorPort, motorInput1, PIN_OUTPUT);
	GPIO_setupPinDirection(motorPort, motorInput2, PIN_OUTPUT);

	/* stop the motor at the begining */
	GPIO_writePin(motorPort, motorInput1 , LOGIC_LOW);
	GPIO_writePin(motorPort, motorInput2 , LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state, uint8 speed){

	switch(state){
	case CLOCKWISE:
		GPIO_writePin(motorPort, motorInput1 , LOGIC_HIGH);
		GPIO_writePin(motorPort, motorInput2 , LOGIC_LOW);
		PWM_Timer0_Start(speed);
		break;
	case ANTI_CLOCKWISE:
		GPIO_writePin(motorPort, motorInput1 , LOGIC_LOW);
		GPIO_writePin(motorPort, motorInput2 , LOGIC_HIGH);
		PWM_Timer0_Start(speed);
		break;
	case STOP:
		GPIO_writePin(motorPort, motorInput1 , LOGIC_LOW);
		GPIO_writePin(motorPort, motorInput2 , LOGIC_LOW);
		break;
	}


}
