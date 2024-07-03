/*
 * SPI_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: hp
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_init(void);
void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_SendData(u8 Copy_U8Data); //Master is Send
u8 SPI_ReceiveData(void); //Slave is Receive
u8 SPI_ExcahngeData(u8 Copy_U8Data);

#endif /* SPI_INTERFACE_H_ */
