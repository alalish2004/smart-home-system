/*
 * dcmotor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include"std_types.h"

#define motorPort      PORTB_ID
#define motorInput1    PIN0_ID
#define motorInput2    PIN1_ID
#define motorEnable    PIN3_ID

typedef enum
{
	CLOCKWISE,ANTI_CLOCKWISE,STOP
}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DCMOTOR_H_ */
