/*
 * app.c
 *
 *  Created on: Oct 13, 2023
 *      Author: hp
 */

#include "app.h"

void app_init(void){
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTOR_PIN2;
	motor.motor_pin3 = MOTOR_PIN3;
	motor.motor_pin4 = MOTOR_PIN4;

	//LED init
	LED_voidInit(LED_PIN);
	//LCD init
	CLCD_init();
	//KPD init
	KPD_init();
	//MOTOR init
	DCMotor_init(&motor);
}

void Welcom_Page(void){
	//strings in LCD
	u8 happyface[]    = {0x1F,0x11,0x1B,0x11,0x1F,0x11,0x1F,0x00};
	u8 nullChar[]     = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

	// Define character at different CGRAM addresses
	CLCD_Draw_Char(1,happyface);
	CLCD_Draw_Char(0,nullChar);
	u8 wordWELCOME[]  = "WELCOME";

	//Welcome Screen
	CLCD_GoTo(1,6);
	CLCD_WriteString(wordWELCOME);

	CLCD_WriteData_Pos(1,2,1);
	_delay_ms(500);
	CLCD_WriteData_Pos(0,2,1);
	_delay_ms(500);

	CLCD_WriteData_Pos(1,2,3);
	_delay_ms(500);
	CLCD_WriteData_Pos(0,2,3);

	CLCD_WriteData_Pos(1,2,8);
	_delay_ms(500);
	CLCD_WriteData_Pos(0,2,8);

	CLCD_WriteData_Pos(1,2,11);
	_delay_ms(500);
	CLCD_WriteData_Pos(0,2,11);

	CLCD_WriteData_Pos(1,2,16);
	_delay_ms(500);
	CLCD_WriteData_Pos(0,2,16);
	_delay_ms(500);
}

void Home_Page(void){
	//Home page
	u8 wordCONTROL[]  = "CONTROL";
	u8 wordSTATUS[]   = "STATUS";
	//1-CONTROL
	CLCD_WriteNum_Pos(1,1,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordCONTROL,1,3);

	//2-STATUS
	CLCD_WriteNum_Pos(2,2,1);
	CLCD_WriteData_Pos('-',2,2);
	CLCD_WriteString_Pos(wordSTATUS,2,3);
}

void Control_Choice(void){
	//Control Choice Page
	u8 wordLED[]      = "LED";
	u8 wordDC_MOTOR[] = "DC-MOTOR";
	CLCD_WriteNum_Pos(1,1,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordLED,1,3);
	CLCD_WriteNum_Pos(2,2,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordDC_MOTOR,2,3);
}

void Control_LED_Choice(void){
	u8 wordLED_ON[]  = "LED_ON";
	u8 wordLED_OFF[] = "LED_OFF";
	CLCD_WriteNum_Pos(1,1,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordLED_ON,1,3);
	CLCD_WriteNum_Pos(2,2,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordLED_OFF,2,3);
}

void Control_DC_MOTOR_Choice(void){
	u8 wordDC_MOTOR_ON[]  = "DC_MOTOR_ON";
	u8 wordDC_MOTOR_OFF[] = "DC_MOTOR_OFF";
	CLCD_WriteNum_Pos(1,1,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordDC_MOTOR_ON,1,3);
	CLCD_WriteNum_Pos(2,2,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordDC_MOTOR_OFF,2,3);
}

void Control_DC_MOTOR_ON_Choice(void){
	u8 wordDC_MOTOR_ON_CW[] = "DC_MOTOR_ON_CW";
	u8 wordDC_MOTOR_ON_CCW[] = "DC_MOTOR_ON_CCW";
	CLCD_WriteNum_Pos(1,1,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordDC_MOTOR_ON_CW,1,3);
	CLCD_WriteNum_Pos(2,2,1);
	CLCD_WriteData_Pos('-',1,2);
	CLCD_WriteString_Pos(wordDC_MOTOR_ON_CCW,2,3);
}

void DC_MOTOR_CW_ON(void){
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTOR_PIN2;
	motor.motor_pin3 = MOTOR_PIN3;
	motor.motor_pin4 = MOTOR_PIN4;

	DCMotor_SetCW(&motor);
}

void DC_MOTOR_CCW_ON(void){
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTOR_PIN2;
	motor.motor_pin3 = MOTOR_PIN3;
	motor.motor_pin4 = MOTOR_PIN4;

	DCMotor_SetCCW(&motor);
}

void DC_MOTOR_OFF(void){
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTOR_PIN2;
	motor.motor_pin3 = MOTOR_PIN3;
	motor.motor_pin4 = MOTOR_PIN4;

	DCMotor_OFF(&motor);
}

void Status_Choice(void){
	u8 wordLED_ON[]  = "LED_ON";
	u8 wordLED_OFF[] = "LED_OFF";
	u8 wordDC_MOTOR_OFF[] = "DC_MOTOR_OFF";
	u8 wordDC_MOTOR_ON_CW[] = "DC_MOTOR_ON_CW";
	u8 wordDC_MOTOR_ON_CCW[] = "DC_MOTOR_ON_CCW";

	u8 ledpin = DIO_u8GetPinValue(LED_PORT,LED_PIN);
	if(ledpin == DIO_u8HIGH){
		CLCD_WriteString_Pos(wordLED_ON,1,1);
	}else{
		CLCD_WriteString_Pos(wordLED_OFF,1,1);
	}
	/*
	 * CW  -> pin 2,3
	 * CCW -> pin 1,4
	 * */
	u8 motorpin1 = DIO_u8GetPinValue(MOTOR_PORT,MOTOR_PIN1);
	u8 motorpin2 = DIO_u8GetPinValue(MOTOR_PORT,MOTOR_PIN2);
	u8 motorpin3 = DIO_u8GetPinValue(MOTOR_PORT,MOTOR_PIN3);
	u8 motorpin4 = DIO_u8GetPinValue(MOTOR_PORT,MOTOR_PIN4);

	if((motorpin1 == DIO_u8LOW) && (motorpin2 == DIO_u8HIGH) && (motorpin3 == DIO_u8HIGH) && (motorpin4 == DIO_u8LOW)){
		CLCD_WriteString_Pos(wordDC_MOTOR_ON_CW,2,1);
	}else if((motorpin1 == DIO_u8HIGH) && (motorpin2 == DIO_u8LOW) && (motorpin3 == DIO_u8LOW) && (motorpin4 == DIO_u8HIGH)){
		CLCD_WriteString_Pos(wordDC_MOTOR_ON_CCW,2,1);
	}else{
		CLCD_WriteString_Pos(wordDC_MOTOR_OFF,2,1);
	}
}



