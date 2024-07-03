/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#define PORTA (*(volatile unsigned char*)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PORTB (*(volatile unsigned char*)0x38)
#define DDRB (*(volatile unsigned char*)0x37)
#define PORTC (*(volatile unsigned char*)0x35)
#define DDRC (*(volatile unsigned char*)0x34)

int main(void){
	DDRA =  0b00000000;  //0
	DDRB =  0b10000000;	//128
	DDRC =  0b11111111;  //255

	if ((DDRA > DDRB) && (DDRA > DDRC)) //A
	{
		PORTA = 0b11111111;
	}else if ((DDRB > DDRA) && (DDRB > DDRC)){ //B
		PORTB = 0b11111111;
	}else if ((DDRC > DDRA) && (DDRC > DDRB)){ //C
		PORTC = 0b11111111;
	}

	while(1){

	}
}
