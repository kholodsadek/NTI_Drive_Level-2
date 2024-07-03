/*
 * TIMER_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_init(void);
void TIMER0_SetCallBackOv(void (*ptr_to_fun)(void));
void TIMER0_SetCallBackCTC(void (*ptr_to_fun)(void));
void TIMER0_SetPreloadValue(u8 Copy_u8Preload);
void TIMER0_SetCompareMatchValue(u8 Copy_u8Vaue);

#endif /* TIMER_INTERFACE_H_ */
