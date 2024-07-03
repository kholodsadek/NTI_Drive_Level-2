/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#include <avr/io.h>
#include <util/delay.h>

#define ZERO  0b00111111
#define ONE   0b00111111
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111

int SSD_Arr[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

int main(void){
	DDRA = 0xff;
	//PORTA = SSD_Arr[8];
	int i;
	while(1){
		for(i=0;i<10;i++)
		{
			PORTA = SSD_Arr[i]; // Display the number on the 7-segment display
			_delay_ms(200);
		}
	}
}
