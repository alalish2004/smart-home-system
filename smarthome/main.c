/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ALI
 */
#include "adc.h"
#include "pwm.h"
#include "gpio.h"
#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "lm35_sensor.h"
#include "flame.h"
#include "dcmotor.h"
#include "ldr.h"
#include <avr/io.h>
#include <util/delay.h>

#define no_flame       0
#define yes_flame      1
#define lcd_first_row  0
#define lcd_second_row 1

uint8 flame_flag = no_flame;
uint8 alert_mode = 0;
uint8 normal_mode =0;
uint8 initial_motor_state;
uint8 new_motor_state;

void lighting_control(void){
	uint16 lighting = LDR_getLightIntensity();
	if(lighting <= 15){
		LED_on(LED_RED_PIN);
		LED_on(LED_BLUE_PIN);
		LED_on(LED_GREEN_PIN);
	}
	else if(lighting > 15 && lighting<= 50){
		LED_on(LED_RED_PIN);
		LED_off(LED_BLUE_PIN);
		LED_on(LED_GREEN_PIN);
	}
	else if(lighting > 50 && lighting <=70){
		LED_on(LED_RED_PIN);
		LED_off(LED_BLUE_PIN);
		LED_off(LED_GREEN_PIN);
	}
	else{
		LED_off(LED_RED_PIN);
		LED_off(LED_BLUE_PIN);
		LED_off(LED_GREEN_PIN);
	}
}


void automatic_fan_speed(void){
	//DDRA |= (1<<7);
	uint8 temperature = LM35_getTemperature();
	if(temperature < 25){
		DcMotor_Rotate(STOP, 0);
	}
	else if(temperature >=25 && temperature <30){
		DcMotor_Rotate(CLOCKWISE, 25);
	}
	else if(temperature >=30 && temperature <35){
		DcMotor_Rotate(CLOCKWISE, 50);
		//PWM_Timer0_Start(50);

	}
	else if(temperature >=35 && temperature <40){
		DcMotor_Rotate(CLOCKWISE, 75);
	}
	else {
		DcMotor_Rotate(CLOCKWISE, 100);
	}


}

void lcd_display(void){
	uint8 temperature = LM35_getTemperature();
	uint8 lighting = LDR_getLightIntensity();

	if(flame_flag == yes_flame){
		normal_mode=0;
		if(alert_mode == 0){
			LCD_clearScreen();
			alert_mode =1;
		}
		LCD_displayStringRowColumn(lcd_first_row,0,"critical alert!!");
		LCD_displayStringRowColumn(lcd_second_row,0,"flame detected");
	}
	else{
		alert_mode=0;
		if(normal_mode==0){
			LCD_clearScreen();
			normal_mode=1;
		}
		if(temperature < 25){
			LCD_displayStringRowColumn(lcd_first_row,2,"FAN IS OFF");
		}
		else{
			LCD_displayStringRowColumn(lcd_first_row,2,"FAN IS ON ");
		}
		if(temperature>=100){
			LCD_displayStringRowColumn(lcd_second_row,0,"TEMP=");
			LCD_moveCursor(lcd_second_row,5);
			LCD_intgerToString(temperature);
		}
		if(temperature<10){
			LCD_displayStringRowColumn(lcd_second_row,0,"TEMP=");
			LCD_displayStringRowColumn(lcd_second_row,6," ");
			LCD_moveCursor(lcd_second_row,5);
			LCD_intgerToString(temperature);
		}
		else{
			LCD_displayStringRowColumn(lcd_second_row,0,"TEMP=");
			LCD_displayStringRowColumn(lcd_second_row,7," ");
			LCD_moveCursor(lcd_second_row,5);
			LCD_intgerToString(temperature);
		}
		if(lighting==100){
			LCD_displayStringRowColumn(lcd_second_row,8,"LDR=");
			LCD_moveCursor(lcd_second_row,12);
			LCD_intgerToString(lighting);
		}
		if(lighting < 10){
			LCD_displayStringRowColumn(lcd_second_row,8,"LDR=");
			LCD_displayStringRowColumn(lcd_second_row,13," ");
			LCD_moveCursor(lcd_second_row,12);
			LCD_intgerToString(lighting);
		}
		else{
			LCD_displayStringRowColumn(lcd_second_row,8,"LDR=");
			LCD_displayStringRowColumn(lcd_second_row,14," ");
			LCD_moveCursor(lcd_second_row,12);
			LCD_intgerToString(lighting);
		}

	}
}

void flame_sensor(void){
	flame_flag = FlameSensor_getValue();
	if(flame_flag){
		Buzzer_on();
	}
	else{
		Buzzer_off();
	}
}



int main(void){
	ADC_init();
	Buzzer_init();
	DcMotor_Init();
	FlameSensor_init();
	LCD_init();
	LEDS_init();

	while(1){
		lighting_control();
		automatic_fan_speed();
		lcd_display();
		flame_sensor();
	}
}

