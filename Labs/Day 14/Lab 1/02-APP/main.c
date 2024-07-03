/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#include "../01-LIB/STD_TYPES.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"
#include "../04-MCAL/02-EXTI/EXTI_Interface.h"
#include "../04-MCAL/04-GIE/GIE_Interface.h"
#include "util/delay.h"
#include "../04-MCAL/05-TIMER0/TIMER0_Interface.h"
#include "../04-MCAL/05-TIMER0/TIMER0_Private.h"

void OverFlow_vector(void){
	static u32 counter = 0;
	counter++;
	if (counter == 1953){
		DIO_voidToggleValue(DIO_u8PORTA, DIO_U8PIN0);
		counter = 0;
		TCNT0 = 224;
	}
}

void CTC_vector(void){
	static u32 counter = 0;
	counter++;
	if (counter == 499){
		DIO_voidToggleValue(DIO_u8PORTA, DIO_U8PIN0);
		counter = 0;
	}
}

int main(void){
	TIMER0_init();
	//CTC_MODE
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_U8PIN0, DIO_u8OUTPUT);
	TIMER0_SetCallBackCTC(CTC_vector);
	TIMER0_SetCompareMatchValue(125); //OCR0 -> ..255
	GIE_EnableInterrupts();

	//OVERFLOW_MODE
/*	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_U8PIN0, DIO_u8OUTPUT);
	TIMER0_SetCallBackOv(OverFlow_vector);
	TIMER0_SetPreloadValue(224); //TCNT0 = 224
	GIE_EnableInterrupts();*/


	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_U8PIN7, DIO_u8OUTPUT);
	while(1){
		DIO_voidSetPinValue(DIO_u8PORTA, DIO_U8PIN7, DIO_u8LOW);
		_delay_ms(500);
		DIO_voidSetPinValue(DIO_u8PORTA, DIO_U8PIN7, DIO_u8HIGH);
		_delay_ms(500);
	}
}
