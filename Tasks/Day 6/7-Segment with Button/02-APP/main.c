/*
 * main.c
 *
 *  Created on: Oct 9, 2023
 *      Author: hp
 */

#include "../01-LIB/STD_TYPES.h"
#include "../03-HAL/02-SEVEN_SEGMENT/SEVEN_SEGMENT_Interface.h"
#include "../03-HAL/03-BUSH_BUTTON/BushButton_Interface.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"

int main(void){
	Button myButton;
	myButton.button_pin = DIO_U8PIN0;
	myButton.button_port = DIO_u8PORTC;
	u8 counter = 0;
	SevenSegment_voidInit();
	BushButton_voidInit(&myButton);

	Segment_voidDispaly(88);
	_delay_ms(1000);

	while(1){
		u8 read = BushButton_voidRead(&myButton);
		if (read == Button_PRESSESD){
			Segment_voidDispaly(counter);
		}else if (read == Button_RELEASED){
			Segment_voidDispaly(0);
		}

		if (read == Button_PRESSESD) {
			counter++;
			if (counter == 100) {
				counter = 0;
			}
		}
	}
}
