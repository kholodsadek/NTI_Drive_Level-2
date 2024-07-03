/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#include "util/delay.h"
#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "../03-HAL/02-SEVEN_SEGMENT/SEVEN_SEGMENT_Interface.h"


int main(void){
	LED_voidInit(DIO_U8PIN0);
	LED_voidInit(DIO_U8PIN1);
	LED_voidInit(DIO_U8PIN2);
	SevenSegment_voidInit();

	u8 green_led = DIO_U8PIN2; //60s
	u8 yellow_led = DIO_U8PIN1; //15s
	u8 red_led = DIO_U8PIN0;  //60s


	while(1){
		LED_voidON(green_led);
		SevenSegment_voidDispaly(60);
		LED_voidOFF(green_led);

		LED_voidON(yellow_led);
		SevenSegment_voidDispaly(15);
		LED_voidOFF(yellow_led);

		LED_voidON(red_led);
		SevenSegment_voidDispaly(60);
		LED_voidOFF(red_led);

		LED_voidON(yellow_led);
		SevenSegment_voidDispaly(15);
		LED_voidOFF(yellow_led);
	}
}
