/*
 * UART_Interface.h
 *
 *  Created on: Oct 28, 2023
 *      Author: hp
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void USART_voidInit(void);
void USART_voidSendData(u8 Copy_U8Data);
u8 USART_u8ReceiveData(void);

#endif /* UART_INTERFACE_H_ */
