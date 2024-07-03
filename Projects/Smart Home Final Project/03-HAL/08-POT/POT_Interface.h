/*
 * POT_Interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: hp
 */

#ifndef POT_INTERFACE_H_
#define POT_INTERFACE_H_

#define ADC_CHANNEL ADC_CHANNEL_A0

void POT_init(void);
void POT_CallValue(u32 * Copy_u8Digital, u32 * Copy_u8Volt);

#endif /* POT_INTERFACE_H_ */
