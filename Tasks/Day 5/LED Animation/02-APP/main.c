/*
 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: hp
 */

#include "../01-LIB/STD_TYPES.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "util/delay.h"

int main(void){
	LEDs_voidInit(0xff);
	u8 i,j,e;

	/* Task 1 */
	for (i = 0; i < 4; i++){
		for (j = 0; j < 8; j++){
			LED_voidON(j);
			_delay_ms(200);
			LED_voidOFF(j);
			_delay_ms(200);
		}
		for (j = 6; j > 0; j--){
			LED_voidON(j);
			_delay_ms(200);
			LED_voidOFF(j);
			_delay_ms(200);
		}
	}

	/* Task 2 */
	for (e = 0; e < 4; e++){
		for (j = 4,i = 3; j <= 7 && i >= 0 ; j++,i--){
					LED_voidON(i); //3  2  1  0
					LED_voidON(j); //4  5  6  7
					_delay_ms(200);
		}
		for (j = 7,i = 0; j >= 4 && i <= 3 ; j--,i++){
					LED_voidOFF(i); //7  6  5  4
					LED_voidOFF(j); //0  1  2  3
					_delay_ms(200);
		}
	}

	/* Task 3 */
	for (e = 0; e < 8; e++){
		LEDs_voidON(0xff);
		_delay_ms(500);
		LEDs_voidOFF(0x00);
		_delay_ms(500);
	}
	while(1){

	}
}
