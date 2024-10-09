################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../buzzer.c \
../dcmotor.c \
../flame.c \
../gpio.c \
../lcd.c \
../ldr.c \
../led.c \
../lm35_sensor.c \
../main.c \
../pwm.c 

OBJS += \
./adc.o \
./buzzer.o \
./dcmotor.o \
./flame.o \
./gpio.o \
./lcd.o \
./ldr.o \
./led.o \
./lm35_sensor.o \
./main.o \
./pwm.o 

C_DEPS += \
./adc.d \
./buzzer.d \
./dcmotor.d \
./flame.d \
./gpio.d \
./lcd.d \
./ldr.d \
./led.d \
./lm35_sensor.d \
./main.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


