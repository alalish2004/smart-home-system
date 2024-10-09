/*
 * flame.h
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */

#ifndef FLAME_H_
#define FLAME_H_

#include "std_types.h"

#define FLAME_PORT_ID PORTD_ID
#define FLAME_PIN_ID  PIN2_ID
#define fire_on   1
#define fire_off  0

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);


#endif /* FLAME_H_ */
