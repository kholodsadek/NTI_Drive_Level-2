/*
 * SPI_Program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: hp
 */

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"

void SPI_init(){
#if SPI_MODE == SLAVE_MODE
	/* SPI Slave Init */
	CLR_BIT(SPCR, SPCR_MSTR);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);

#elif SPI_MODE == MASTER_MODE
	/* SPI Master Init */
	SET_BIT(SPCR, SPCR_MSTR);

	/* Clock: Div by 16 */
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);

#endif

}

void SPI_MasterInit(void){
	/* SPI Master Init */
	SET_BIT(SPCR, SPCR_MSTR);

	/* Clock: Div by 16 */
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);
}

void SPI_SlaveInit(void){
	/* SPI Slave Init */
	CLR_BIT(SPCR, SPCR_MSTR);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);
}

void SPI_SendData(u8 Copy_U8Data){
	/*  Send the data */
	SPDR = Copy_U8Data;
	/* Wait for transmission complete */
	while(GET_BIT(SPSR, SPSR_SPIF) == 0);
}

u8 SPI_ReceiveData(void){
	/* Wait for receive complete */
	while(GET_BIT(SPSR, SPSR_SPIF) == 0);
	/* Return data register */
	return SPDR;
}

u8 SPI_ExcahngeData(u8 Copy_U8Data){
	/* Send the date */
	SPDR = Copy_U8Data;

	while(GET_BIT(SPSR, SPSR_SPIF) == 0);

	return SPDR;

}
