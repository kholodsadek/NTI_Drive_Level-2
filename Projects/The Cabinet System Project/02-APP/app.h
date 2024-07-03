/*
 * app.h
 *
 *  Created on: Oct 22, 2023
 *      Author: hp
 */

#ifndef APP_H_
#define APP_H_

/* Section Includes*/
#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"
#include "../03-HAL/02-SEVEN_SEGMENT/SEVEN_SEGMENT_Interface.h"
#include "../03-HAL/04-CLCD/CLCD_Interface.h"
#include "../03-HAL/05-KPD/KPD_Interface.h"
#include "../03-HAL/06-DC_MOTOR/DC_Motor_Interface.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"

/* Section: Macros Configuration */
#define BUZZER_PIN     DIO_U8PIN7
#define MOTOR_PORT     DIO_u8PORTB
#define MOTOR_PIN1     DIO_U8PIN3
#define MOTOR_PIN2     DIO_U8PIN4
#define MOTOR_PIN3     DIO_U8PIN5
#define MOTOR_PIN4     DIO_U8PIN6

/* APIs Supported by "APP" */
void app_init(void);
u8 Read_Pasword(void);
void MOTOR_ON(void);
void BUZZER_ON(void);
void Halt_System(void);

#endif /* APP_H_ */
