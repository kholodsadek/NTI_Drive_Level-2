/*
 * BushButton_Interface.h
 *
 *  Created on: Oct 9, 2023
 *      Author: hp
 */

#ifndef BUSHBUTTON_INTERFACE_H_
#define BUSHBUTTON_INTERFACE_H_

#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"
#include "util/delay.h"


typedef enum {
	Button_PRESSESD =0,
	Button_RELEASED
}button_state;

typedef struct {
	u8 button_pin;
	u8 button_port;
	button_state button;
}Button;

void BushButton_voidInit(Button *button);
u8 BushButton_voidRead(Button *button);

#endif /* BUSHBUTTON_INTERFACE_H_ */
