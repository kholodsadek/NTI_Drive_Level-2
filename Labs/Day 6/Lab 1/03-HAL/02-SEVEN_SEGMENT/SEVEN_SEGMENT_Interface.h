/*
 * SEVEN_SEGMENT_Interface.h
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_

#define SEVEN_SEGMENT_PORT DIO_u8PORTA

#define ZERO  0b00111111
#define ONE   0b00000110
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111


void SevenSegment_voidInit();
void SevenSegment_voidDispaly(u8 Copy_u8Seconds);

#endif /* SEVEN_SEGMENT_INTERFACE_H_ */
