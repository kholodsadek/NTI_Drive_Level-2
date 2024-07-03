/*
 * main.c
 *
 *  Created on:			 Oct 21, 2023
 *  Author:				 Kholod_Sadek
 *  The_Project_Name:    The_Cabiniet_Ststem
 */

#include "app.h"
#include "util/delay.h"


int main(void){
	app_init();

	u8 remainingNum = 3;

	//LCD words
	u8 wordTryAgain[]          = "Try Again!";
	u8 wordSuccessfullyLogin[]      = "Successfully login!";

	while(1){
		SevenSegment_voidDispaly(remainingNum);
		if(Read_Pasword()){ //wrong password
			remainingNum--;
			if(remainingNum == 0){ //the password is incorrect 3 times
				SevenSegment_voidDispaly(remainingNum);
				Halt_System();
			}else{
				CLCD_DisplayClear();
				CLCD_WriteString(wordTryAgain);
				_delay_ms(500);
				CLCD_DisplayClear();
				continue;
			}
		}
		else{ //right password
			CLCD_DisplayClear();
			CLCD_WriteString(wordSuccessfullyLogin);
			_delay_ms(500);
			CLCD_DisplayClear();
			MOTOR_ON();
		}
	}
}

