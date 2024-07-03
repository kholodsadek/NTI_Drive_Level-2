/*
 * UART_Program.c
 *
 *  Created on: Oct 28, 2023
 *      Author: hp
 */

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"

/* UART_init:
 * one stop Bit --->  UCSRC_USBS 0
 * no parity  --->  UCSRC_UPM0  0 , UCSRC_UPM1  0
 * 8 Bit Data  ----->  UCSRC_UCSZ1  1 ,  UCSRC_UCSZ0  1
 * no Interrupt (polling)
 * Asynch_mode ---->    UCSRC_UMSEL 0
 * 9600 bps Baud Rate  ---> UBRRL = 51 -> value , UBRRH ==(51>>8) -> error
 * Enable of transmitter and receiver ---> UCSRB_RXEN 1 , UCSRB_TXEN 1 */
void USART_voidInit(void){
	/* Enable of transmitter and receiver */
		SET_BIT(UCSRB, UCSRB_RXEN);
		SET_BIT(UCSRB, UCSRB_TXEN);

		/* 9600 bps Baud Rate */
		u16 BaudRate = 51;
		UBRRH = (u8)(BaudRate>>8);
		UBRRL = (u8)BaudRate;

		/* Frame format configuration */
		//UCSRC = 0b10000110;
		//UCSRC_UCSZ0 UCSRC_UCSZ1  UCSRC_URSEL
		CLR_BIT(UCSRC, UCSRC_USBS);  //one stop Bit
		CLR_BIT(UCSRC, UCSRC_UPM0);  //no parity
		CLR_BIT(UCSRC ,UCSRC_UPM1);  //no parity
		SET_BIT(UCSRC ,UCSRC_UCSZ1); //8 Bit Data
		SET_BIT(UCSRC ,UCSRC_UCSZ0); //8 Bit Data
		CLR_BIT(UCSRC ,UCSRC_UMSEL); //Asynch_mode
		SET_BIT(UCSRC, UCSRC_URSEL); //writing the UCSRC.
}

void USART_voidSendData(u8 Copy_U8Data){
	/* Check on UDRE Flag */
	while (GET_BIT(UCSRA,UCSRA_UDRE)==0);

	/* Send Data */
	UDR = Copy_U8Data;
}

u8 USART_u8ReceiveData(void){
	/* Check on RXC Flag */
	while (GET_BIT(UCSRA,UCSRA_RXC)==0);

	/* return data */
	return UDR;
}
