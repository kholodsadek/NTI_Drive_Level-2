/*
 * LDR_Interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: hp
 */

#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

#define ADC_CHANNEL_LDR ADC_CHANNEL_A1

void LDR_init(void);
u16 LDR_CallValue(void);

#endif /* LDR_INTERFACE_H_ */
