/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#define DDRA  (*(volatile unsigned char *) 0X3A)
#define PORTA (*(volatile unsigned char *) 0X3B)
#define DDRB  (*(volatile unsigned char *) 0X37)
#define PORTB (*(volatile unsigned char *) 0X38)

int main(void){
	DDRA =  0b00000011;
	DDRB =  0b00000011;
	PORTA = 0b00000011;
	PORTB = 0b00000000;
	while(1){

	}
}
