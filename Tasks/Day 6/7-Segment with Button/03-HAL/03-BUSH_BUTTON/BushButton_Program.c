/*
 * BushButton_Program.c
 *
 *  Created on: Oct 9, 2023
 *      Author: hp
 */

#include "BushButton_Interface.h"

void BushButton_voidInit(Button *button){
	DIO_voidSetPinDirection(button->button_port, button->button_pin, DIO_u8INPUT);
}

u8 BushButton_voidRead(Button *button){
    u8 local_u8Read = DIO_u8GetPinValue(button->button_port, button->button_pin);
    static button_state lastButtonState = Button_RELEASED; // Static variable to remember the last state

    if (local_u8Read == 0 && lastButtonState == Button_RELEASED) {
        // Button was just pressed
        lastButtonState = Button_PRESSESD;
    } else if (local_u8Read == 1 && lastButtonState == Button_PRESSESD) {
        // Button was just released
        lastButtonState = Button_RELEASED;
    }else {
    	lastButtonState = Button_RELEASED;
    }

    return lastButtonState;
}





