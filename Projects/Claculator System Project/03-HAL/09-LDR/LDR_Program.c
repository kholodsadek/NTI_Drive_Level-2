/*
 * LDR_Program.c
 *
 *  Created on: Oct 21, 2023
 *      Author: hp
 */

#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/03-ADC/ADC_Interface.h"
#include "LDR_Interface.h"

void LDR_init(void){
	ADC_voidInit();
}

u16 LDR_CallValue(void){
	u16 Local_u16Digital = ADC_u8StartConversion(ADC_CHANNEL);
/* 	if (digital > 512){
		MDIO_vSetPinValue(PORT_D,0,LOW);
	}else {
		MDIO_vSetPinValue(PORT_D,0,HIGH);
	} */
	return Local_u16Digital;
}
