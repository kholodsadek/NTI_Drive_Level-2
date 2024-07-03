/*
 * TIMER_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#include  "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"

#include "../05-TIMER0/TIMER0_Config.h"
#include "../05-TIMER0/TIMER0_Interface.h"
#include "../05-TIMER0/TIMER0_Private.h"

#define NULL 0

void (*TIMER0_OV)(void)  = NULL;
void (*TIMER0_CTC)(void)  = NULL;

void TIMER0_init(void){
#if TIMER0_MODE == NORMAL_MODE
	/* Normal mode */
	CLR_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);

	if (CLOCK_SELECT == PRESCALER_64){
		/* Prescalar : /64 */
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
	}else if (CLOCK_SELECT == PRESCALER_8){
		/* Prescalar : /8 */
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
	}

	/* Turn on interrupt */
	SET_BIT(TIMSX, TOIE0);

#elif TIMER0_MODE == CTC_MODE
	/* CTC mode */
	SET_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);

	/* Disconnect OC0 : Normal pin */
	CLR_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);

	if (CLOCK_SELECT == PRESCALER_64){
		/* Prescalar : /64 */
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
	}else if (CLOCK_SELECT == PRESCALER_8){
		/* Prescalar : /8 */
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
	}

	/* Reset OCR0 */
	OCR0 = 0;
	/* Turn on interrupt */
	SET_BIT(TIMSX, OCIE0);

#endif
}

void TIMER0_SetCallBackOv(void (*ptr_to_fun)(void)){
	TIMER0_OV = ptr_to_fun;
}
void TIMER0_SetCallBackCTC(void (*ptr_to_fun)(void)){
	TIMER0_CTC = ptr_to_fun;
}
void TIMER0_SetPreloadValue(u8 Copy_u8Preload){ //OVERFLOW_MODE
	TCNT0 = Copy_u8Preload;
}
void TIMER0_SetCompareMatchValue(u8 Copy_u8Vaue){ //CTC_MODE
	OCR0 = Copy_u8Vaue;
}

void __vector_11(void){
	if (TIMER0_OV != NULL){
		TIMER0_OV();
	}
}
void __vector_10(void){
	if (TIMER0_CTC != NULL){
		TIMER0_CTC();
	}
}
