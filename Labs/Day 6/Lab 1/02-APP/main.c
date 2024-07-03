/*
 * main.c
 *
 *  Created on: Oct 9, 2023
 *      Author: hp
 */

#include "../01-LIB/STD_TYPES.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "util/delay.h"

int main(void){

	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_U8PIN3, DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_U8PIN2, DIO_u8INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD,DIO_U8PIN2,DIO_u8HIGH);

	while(1){
		u8 read;
		read = DIO_u8GetPinValue(DIO_u8PORTD, DIO_U8PIN2);
		if (read == 0){
			_delay_ms(150);
			if (read == 0){
				LED_voidOFF(DIO_U8PIN3);
			}
		} else if (read == 1){
			LED_voidON(DIO_U8PIN3);
		}
	}
}
