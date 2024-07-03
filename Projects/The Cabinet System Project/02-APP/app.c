/*
 * app.c
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#include "app.h"

//System PASSWORD
#define SYSTEM_PSW 1234

void app_init(void){
	/* LCD init */
	CLCD_init();
	/* KPD init */
	KPD_init();
	/* DC_MOTOR init */
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTOR_PIN2;
	motor.motor_pin3 = MOTOR_PIN3;
	motor.motor_pin4 = MOTOR_PIN4;
	DCMotor_init(&motor);
	/* Buzzer init */
	DIO_voidSetPinDirection(DIO_u8PORTB, DIO_U8PIN7, DIO_u8OUTPUT);
	/* SSD init*/
	SevenSegment_voidInit();
}

u8 Read_Pasword(void){
	/*
	 * Read password from keypad
	 * If password is correct, return 0
	 * If password is incorrect, return 1
	 */
	u8 wordEnterYourPassword[] = "Enter your Password: ";
	u8 keypad_entry;
	u32 password = 0;
	CLCD_WriteString(wordEnterYourPassword);
	CLCD_GoTo(2,1);

	while(1){
		keypad_entry = KPD_GetPressedKey();

		if (keypad_entry == '='){
			break;
		} else if ((keypad_entry >= '0') && (keypad_entry <= '9')){
			CLCD_WriteData(keypad_entry);
			password += (keypad_entry - 48);
			password *= 10;
		} else {  /* Do Nothing */  }
	}

	password /= 10;

	// Check if the entered password is correct
	u8 ret_val = (password == SYSTEM_PSW) ? 0 : 1;
	return ret_val;
}

void MOTOR_ON(void){
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTOR_PIN2;
	motor.motor_pin3 = MOTOR_PIN3;
	motor.motor_pin4 = MOTOR_PIN4;
	while(1){
		DCMotor_SetCW(&motor);
	}
}

void BUZZER_ON(void){
	DIO_voidSetPinValue(DIO_u8PORTB, DIO_U8PIN7, DIO_u8HIGH);
}


void Halt_System(void){
	CLCD_DisplayClear();
	CLCD_WriteString((u8*)"System is halted!");
	while(1){
		BUZZER_ON();
	}
}
