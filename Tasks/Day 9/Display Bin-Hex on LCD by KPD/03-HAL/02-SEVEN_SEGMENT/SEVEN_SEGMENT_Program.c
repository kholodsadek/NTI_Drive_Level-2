/*
 * SEVEN_SEGMENT_Program.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hp
 */

#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"
#include "SEVEN_SEGMENT_Interface.h"
#include "util/delay.h"

u32 SSD_Arr[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

void SevenSegment_voidInit(){
	DIO_voidSetPortDirection(SEVEN_SEGMENT_PORT, 0xff);
	DIO_voidSetPortDirection(SEVEN_SEGMENT_PORT2, 0xff);
}

void SevenSegment_voidDispaly(u8 Copy_u8Seconds){
	u8 i;
	if (Copy_u8Seconds < 10){
		for(i = Copy_u8Seconds; i > 0; i--)
		{
			DIO_voidSetPortValue(SEVEN_SEGMENT_PORT, SSD_Arr[i]);
			_delay_ms(500);
		}
	} else if (Copy_u8Seconds < 99){
		u8 fnum,snum;
		for(i = Copy_u8Seconds; i > 0; i--)
		{
			fnum = i/10;
			snum = i%10;
			DIO_voidSetPortValue(SEVEN_SEGMENT_PORT, SSD_Arr[fnum]);
			DIO_voidSetPortValue(SEVEN_SEGMENT_PORT2, SSD_Arr[snum]);
			_delay_ms(500);
		}
	}
}
