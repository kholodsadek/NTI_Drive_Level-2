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
#include "../03-HAL/05-KPD/KPD_Interface.h"
#include "util/delay.h"

int main(void){
	KPD_init();
	CLCD_init();
	u8 KeyPressed,num=0;
	while(1){
		while (KeyPressed != '='){
			KeyPressed = KPD_GetPressedKey(); //12
			if (KeyPressed == '=')
				break;
			if(KeyPressed != 0){
				CLCD_WriteData(KeyPressed);
				num += (KeyPressed- 48); // 12
				num *= 10; //120
			}
			if (KeyPressed == 'C'){
				num = 0;
				CLCD_DisplayClear();
			}
		}
		num /= 10; //12
		CLCD_WriteData(KeyPressed);
		CLCD_GoTo(2,1);
	    CLCD_PrintBinary(num);
	    CLCD_WriteChar(',');
	    CLCD_printHEXNum(num);
	    _delay_ms(1000);
	    KeyPressed = KPD_GetPressedKey();
	    if (KeyPressed == 'C'){
			num = 0;
			CLCD_DisplayClear();
		}else{

		}
	}
}
