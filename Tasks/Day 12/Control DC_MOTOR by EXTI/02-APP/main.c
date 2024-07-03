/*
 * main.c
 *
 *  Created on: Oct 18, 2023
 *      Author: hp
 */

#include "../01-LIB/STD_TYPES.h"
#include "../03-HAL/06-DC_MOTOR/DC_Motor_Interface.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"
#include "../04-MCAL/02-EXTI/EXTI_Interface.h"
#include "../03-HAL/03-BUSH_BUTTON/BushButton_Interface.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "util/delay.h"

volatile u8 flag =1;

//Toggle motor by just flag
void DC_MOTOR_TOGGLE_byFlag(void){
	Motor motor;
	motor.motor_port = DIO_u8PORTA;
	motor.motor_pin1 = DIO_U8PIN1;
	motor.motor_pin2 = DIO_U8PIN2;
	motor.motor_pin3 = DIO_U8PIN3;
	motor.motor_pin4 = DIO_U8PIN4;

	if(flag % 2 != 0){ //odd
		DCMotor_SetCW(&motor);
	}else if(flag % 2 == 0){ //even
		DCMotor_SetCCW(&motor);
	}
	_delay_ms(3000);
	flag++;
}

//Toggle motor by flag and function DCMotor_Toggle()
void DC_MOTOR_TOGGLE_byFlagAndFun(void){
	Motor motor;
	motor.motor_port = DIO_u8PORTA;
	motor.motor_pin1 = DIO_U8PIN1;
	motor.motor_pin2 = DIO_U8PIN2;
	motor.motor_pin3 = DIO_U8PIN3;
	motor.motor_pin4 = DIO_U8PIN4;

	if (flag == 1){
		DCMotor_SetCW(&motor);
		flag++;
	}
	else if (flag == 2){
		DCMotor_Toggle(&motor);
		flag--;
	}
	_delay_ms(3000);

}

int main(void){
	//SW
	Button button;
	button.button_pin = DIO_U8PIN2;
	BushButton_voidInit(&button);

	//EXTI
	EXTI_init();
	//EXTI_SetCallBack(DC_MOTOR_TOGGLE_byFlag, 0);
	EXTI_SetCallBack(DC_MOTOR_TOGGLE_byFlagAndFun, 0);

	//DC-Motor_PIN
	Motor motor;
	motor.motor_port = DIO_u8PORTA;
	motor.motor_pin1 = DIO_U8PIN1;
	motor.motor_pin2 = DIO_U8PIN2;
	motor.motor_pin3 = DIO_U8PIN3;
	motor.motor_pin4 = DIO_U8PIN4;
	DCMotor_init(&motor);

	//LED
	LED_voidInit(DIO_U8PIN0);

	while(1){
		DCMotor_OFF(&motor);
		LED_voidON(DIO_U8PIN0);
		_delay_ms(500);
		LED_voidOFF(DIO_U8PIN0);
		_delay_ms(500);
	}
}
