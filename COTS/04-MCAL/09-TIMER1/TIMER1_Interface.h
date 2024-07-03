/*
 * TIMER1_Interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: hp
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_init(void);
void TIMER1_SetOCR1AValue(u16 Copy_u16Value);
void TIMER1_SetOCR1BValue(u16 Copy_u16Value);
void TIMER1_SetICR1Value(u16 Copy_u16Value);

#endif /* TIMER1_INTERFACE_H_ */
