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
	u8 KeyPressed;
	u32 num,var_1,var_2,sum=0;

	while(1){
		KeyPressed = KPD_GetPressedKey();
		if(KeyPressed != 0){
			CLCD_WriteData(KeyPressed);
			if(KeyPressed >= '0' && KeyPressed <= '9'){
				num = (num * 10) + (KeyPressed- 48);
			}
			else if(KeyPressed == '+'){
				var_1 = num;
				num = 0;
			}
			else if(KeyPressed == '='){
				if(sum != 0){
					sum +=num;
				}
				else{
					var_2 = num;
					sum = var_1 + var_2;

				}
				CLCD_DisplayClear();
				CLCD_GoTo(1,1);
				CLCD_WriteNum(sum);
			}
			if (KeyPressed == 'C'){
				sum = 0;
				num = 0;
		    	var_1 = 0;
		    	var_1 = 0;
				CLCD_DisplayClear();
			}
		}
	}
}
