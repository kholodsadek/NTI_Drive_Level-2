/*
 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: hp
 */

#include "../01-LIB/STD_TYPES.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "../03-HAL/04-CLCD/CLCD_Interface.h"
#include "util/delay.h"

int main(void){
	CLCD_init();
	u8 myname[] = "kholod";
	while(1){
		CLCD_WriteString(myname);
		_delay_ms(500);
		CLCD_DisplayClear();
		_delay_ms(500);
	}
}
