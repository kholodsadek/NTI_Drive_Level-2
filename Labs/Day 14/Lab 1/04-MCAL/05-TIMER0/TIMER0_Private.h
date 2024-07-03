/*
 * TIMER_Private.h
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0   *((volatile u8 *)0x53)
#define TCNT0   *((volatile u8 *)0x52)
#define TIMSX   *((volatile u8 *)0x59)
#define TIFR    *((volatile u8 *)0x58)
#define OCR0    *((volatile u8 *)0x5C)

/* CTC_MODE    -> WGM01 1 & WGM00 0
 * NORMAL_MODE -> WGM01 0 & WGM00 0 */
/* Prescaler64 -> CS00 1 & CS01 1 & CS02 0
 * Prescaler8  -> CS00 0 & CS01 1 & CS02 0
 *  */

#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7

#define TOIE0  0
#define OCIE0  1

void __vector_11() __attribute__((signal));
void __vector_10() __attribute__((signal));
//These are interrupt service routines (ISRs) that will be called when specific timer events occur.
//ISR __vector_11 is associated with the Timer0 overflow interrupt,
//and ISR __vector_10 is associated with the Timer0 Compare Match interrupt.

#endif /* TIMER_PRIVATE_H_ */
