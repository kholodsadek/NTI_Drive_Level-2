/*
 * EXTI_Interface.h
 *
 *  Created on: Oct 18, 2023
 *      Author: hp
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"


void EXTI_init(void);
void EXTI_SetCallBack(void (*ptr_to_fun)(void),u8 IntID);

#endif /* EXTI_INTERFACE_H_ */
