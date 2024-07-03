/*
 * LED_Interface.h
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_PORT DIO_u8PORTB

void LED_voidInit(u8 u8PinNum);
void LEDs_voidInit(u8 u8PinNum);
void LED_voidON(u8 u8PinNum);
void LEDs_voidON(u8 u8PinNum);
void LED_voidOFF(u8 u8PinNum);
void LEDs_voidOFF(u8 u8PinNum);

#endif /* LED_INTERFACE_H_ */
