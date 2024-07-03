/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"
#include "../03-HAL/04-CLCD/CLCD_Interface.h"
#include "../03-HAL/05-KPD/KPD_Interface.h"


int main(){
	KPD_init();
	CLCD_init();

	u8 keypad_entry,lastOP;
	f64 num,res = 0;
    u8 i = 1,flag = 0;
	while(1){
		keypad_entry = KPD_GetPressedKey();
		if (keypad_entry != 0){
			if((keypad_entry != '+') && (keypad_entry != '-') && (keypad_entry != '*') && (keypad_entry != '/') && (keypad_entry != '=')){
				if (flag == 1){
					CLCD_WriteString_Pos((u8*)"   ",2,1);
					flag = 0;
				}
				CLCD_GoTo(2,i);
				CLCD_WriteData(keypad_entry);
				i++;
			}
			if ((keypad_entry >= '0') && (keypad_entry <= '9')){
				num = (num * 10) + (keypad_entry - 48);
			}else {
				switch (keypad_entry) {
					case '+':
						lastOP = '+';
						res += num;
						CLCD_WriteString_Pos((u8*)"           ",1,1);
						CLCD_GoTo(1,1);
						CLCD_WriteNum(res);
						CLCD_WriteData('+');
						CLCD_WriteString_Pos((u8*)"           ",2,1);
						CLCD_GoTo(2,1);
						CLCD_WriteNum(res);
						num = 0;

						i = 1;
						flag = 1;
						break;
					case '-':
						lastOP = '-';
						if (res == 0){
							res += num;
						}else {
							res -= num;
						}
						CLCD_WriteString_Pos((u8*)"           ",1,1);
						CLCD_GoTo(1,1);
						CLCD_WriteNum(res);
						CLCD_WriteData('-');
						CLCD_WriteString_Pos((u8*)"           ",2,1);
						CLCD_GoTo(2,1);
						CLCD_WriteNum(res);
						num = 0;

						i = 1;
						flag = 1;
						break;
					case '*':
						lastOP = '*';
						if (res == 0){
							res += num;
						}else {
							res *= num;
						}
						CLCD_WriteString_Pos((u8*)"           ",1,1);
						CLCD_GoTo(1,1);
						CLCD_WriteNum(res);
						CLCD_WriteData('*');
						CLCD_WriteString_Pos((u8*)"           ",2,1);
						CLCD_GoTo(2,1);
						CLCD_WriteNum(res);
						num = 0;

						i = 1;
						flag = 1;
						break;
					case '/':
						lastOP = '/';
						if (res == 0){
							res += num;
						}else {
							res /= num;
						}
						CLCD_WriteString_Pos((u8*)"           ",1,1);
						CLCD_GoTo(1,1);
						CLCD_WriteNum(res);
						CLCD_WriteData('/');
						CLCD_WriteString_Pos((u8*)"           ",2,1);
						CLCD_GoTo(2,1);
						CLCD_WriteNum(res);
						num = 0;

						i = 1;
						flag = 1;
						break;
					case '=':
						if (lastOP == '+'){
							CLCD_WriteString_Pos((u8*)"           ",1,1);
							CLCD_GoTo(1,1);
							CLCD_WriteNum(res);
							CLCD_WriteData('+');
							CLCD_WriteNum(num);
							CLCD_WriteData('=');
							res += num;
							CLCD_WriteNum(res);
							CLCD_WriteString_Pos((u8*)"           ",2,1);
							CLCD_GoTo(2,1);
							CLCD_WriteNum(res);
							num = 0;
						}else if (lastOP == '-'){
							CLCD_WriteString_Pos((u8*)"           ",1,1);
							CLCD_GoTo(1,1);
							CLCD_WriteNum(res);
							CLCD_WriteData('-');
							CLCD_WriteNum(num);
							CLCD_WriteData('=');
							res -= num;
							CLCD_WriteNum(res);
							CLCD_WriteString_Pos((u8*)"           ",2,1);
							CLCD_GoTo(2,1);
							CLCD_WriteNum(res);
							num = 0;
						}else if (lastOP == '*'){
							CLCD_WriteString_Pos((u8*)"           ",1,1);
							CLCD_GoTo(1,1);
							CLCD_WriteNum(res);
							CLCD_WriteData('*');
							CLCD_WriteNum(num);
							CLCD_WriteData('=');
							res *= num;
							CLCD_WriteNum(res);
							CLCD_WriteString_Pos((u8*)"           ",2,1);
							CLCD_GoTo(2,1);
							CLCD_WriteNum(res);
							num = 0;
						}else if (lastOP == '/'){
							CLCD_WriteString_Pos((u8*)"           ",1,1);
							CLCD_GoTo(1,1);
							CLCD_WriteNum(res);
							CLCD_WriteData('/');
							CLCD_WriteNum(num);
							CLCD_WriteData('=');
							res /= num;
							CLCD_WriteNum(res);
							CLCD_WriteString_Pos((u8*)"           ",2,1);
							CLCD_GoTo(2,1);
							CLCD_WriteNum(res);
							num = 0;
						}
						break;
					default:
						CLCD_DisplayClear();
						res = 0;
						i = 1;
						flag = 1;
						break;
				}
			}
		}
	}
}
