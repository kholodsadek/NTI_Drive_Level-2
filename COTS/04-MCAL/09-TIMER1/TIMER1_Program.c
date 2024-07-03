/*
 * TIMER1_Program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: hp
 */

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "TIMER1-Config.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Private.h"

void TIMER1_init(void){
	/* Non inverting mode : OC1A, OC1B */
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	/* FAST PWM MODE : TOP ICR1 */
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1B, TCCR1B_WGM13);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	/* prescaling : /8 */
	CLR_BIT(TCCR1B, TCCR1B_CS12);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS10);
}

void TIMER1_SetOCR1AValue(u16 Copy_u16Value){
	OCR1AL = Copy_u16Value;
}

void TIMER1_SetOCR1BValue(u16 Copy_u16Value){
	OCR1BL = Copy_u16Value;
}

void TIMER1_SetICR1Value(u16 Copy_u16Value){
	ICR1L = Copy_u16Value;
}

