/*
 * LM35_Interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: hp
 */

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#define ADC_CHANNEL ADC_CHANNEL_A0

void LM35_init(void);
u32 LM35_CallValue(void);

#endif /* LM35_INTERFACE_H_ */
