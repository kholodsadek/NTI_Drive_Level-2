/*
 * GIE_Program.c
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"

void GIE_EnableInterrupts(void){
	SET_BIT(SREG, 7);  //GIE
}

void GIE_DisableInterrupts(void){
	CLR_BIT(SREG, 7);  //GIE
}
