/*
 * buzzer.h
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_port PORTD_ID
#define BUZZER_pin  PIN3_ID

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);




#endif /* BUZZER_H_ */
