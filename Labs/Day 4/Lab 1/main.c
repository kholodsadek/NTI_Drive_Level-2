/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#define PORTA (*(volatile unsigned char*)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)

int main(void) {
	DDRA = 1;  //0b00000001;
	PORTA = 1; //0b00000001
	while (1) {

	}
}
