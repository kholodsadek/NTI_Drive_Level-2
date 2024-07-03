/*
 * CLCD_Interface.h
 *
 *  Created on: Oct 10, 2023
 *      Author: hp
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"

#define CLCD_Control_Port DIO_u8PORTB
#define CLCD_RS_PIN       DIO_U8PIN0
#define CLCD_RW_PIN       DIO_U8PIN1
#define CLCD_EN_PIN       DIO_U8PIN2
#define CLCD_Data_Port    DIO_u8PORTA


void CLCD_init(void);
void CLCD_WriteInes(u8 A_u8Command); //SendCommand
void CLCD_WriteData(u8 Data); //SendData
void CLCD_WriteChar(u8 Char); //SendChar
void CLCD_WriteString(u8 * String); //SendString
void CLCD_GoTo(u8 Row, u8 Col); //MoveTo
void CLCD_DisplayClear(void);
u8 ConvertNumToASCII(u8 Input);
void CLCD_WriteNum(u64 NUM); //SendNumber
void CLCD_PrintBinary(u8 num);
void CLCD_Draw_Char(u8 Address_Data);
void CLCD_printHEXNum(u8 num);


#endif /* CLCD_INTERFACE_H_ */
