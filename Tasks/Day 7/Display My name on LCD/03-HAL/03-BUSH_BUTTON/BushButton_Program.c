/*
 * BushButton_Program.c
 *
 *  Created on: Oct 9, 2023
 *      Author: hp
 */

#include "BushButton_Interface.h"

void BushButton_voidInit(Button *button){
	DIO_voidSetPinDirection(BUSHBUTTON_PORT, button->button_pin, DIO_u8INPUT);
}

u8 BushButton_voidRead(Button *button){
	u8 local_u8Read = DIO_u8GetPinValue(BUSHBUTTON_PORT, button->button_pin);
	if (local_u8Read == 0){
		_delay_ms(150);
		if (local_u8Read == 0){
			button->button = Button_PRESSESD;
		}
	}else if (local_u8Read == 1){
		button->button = Button_RELEASED;
	}
	return button->button;
}
