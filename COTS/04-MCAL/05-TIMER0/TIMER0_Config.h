/*
 * TIMER_Config.h
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define CTC_MODE    1
#define NORMAL_MODE 0

#define TIMER0_MODE CTC_MODE

#define PRESCALER_8  0
#define PRESCALER_64 1

#define CLOCK_SELECT PRESCALER_64

#endif /* TIMER_CONFIG_H_ */
