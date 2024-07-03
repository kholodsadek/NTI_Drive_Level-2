/*
 * DC_Motor_Program.c
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */

#include "DC_Motor_Interface.h"

void DCMotor_init(Motor *motor){
	DIO_voidSetPinDirection(motor->motor_port, motor->motor_pin1, DIO_u8OUTPUT);
	DIO_voidSetPinDirection(motor->motor_port, motor->motor_pin2, DIO_u8OUTPUT);
	DIO_voidSetPinDirection(motor->motor_port, motor->motor_pin3, DIO_u8OUTPUT);
	DIO_voidSetPinDirection(motor->motor_port, motor->motor_pin4, DIO_u8OUTPUT);
}

void DCMotor_OFF(Motor *motor){
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin1, DIO_u8LOW);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin2, DIO_u8LOW);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin3, DIO_u8LOW);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin4, DIO_u8LOW);
}


/*
 * CW  -> pin 2,3
 * CCW -> pin 1,4
 * */

void DCMotor_SetCW(Motor *motor){
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin1, DIO_u8LOW);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin2, DIO_u8HIGH);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin3, DIO_u8HIGH);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin4, DIO_u8LOW);
}

void DCMotor_SetCCW(Motor *motor){
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin1, DIO_u8HIGH);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin2, DIO_u8LOW);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin3, DIO_u8LOW);
	DIO_voidSetPinValue(motor->motor_port, motor->motor_pin4, DIO_u8HIGH);
}

void DCMotor_Toggle(Motor *motor){
	DIO_voidToggleValue(motor->motor_port, motor->motor_pin1);
	DIO_voidToggleValue(motor->motor_port, motor->motor_pin2);
	DIO_voidToggleValue(motor->motor_port, motor->motor_pin3);
	DIO_voidToggleValue(motor->motor_port, motor->motor_pin4);
}
