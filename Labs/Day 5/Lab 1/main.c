/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void){

	DDRA = 0xff; //port a --> output
	while(1){
		PORTA = 0xff; //port a --> High
		_delay_ms(200);
		PORTA = 0x00; //port a --> low
		_delay_ms(200);
	}
}
