/*
 * ADC_Interface.h
 *
 *  Created on: Oct 20, 2023
 *      Author: hp
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
u16 ADC_u8StartConversion(u8 Copy_u8ChannelNumber);

#define ADC_CHANNEL_A0  0
#define ADC_CHANNEL_A1  1
#define ADC_CHANNEL_A2  2
#define ADC_CHANNEL_A3  3
#define ADC_CHANNEL_A4  4
#define ADC_CHANNEL_A5  5
#define ADC_CHANNEL_A6  6
#define ADC_CHANNEL_A7  7


#endif /* ADC_INTERFACE_H_ */
