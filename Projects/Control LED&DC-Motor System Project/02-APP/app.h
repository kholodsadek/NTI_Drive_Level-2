/*
 * app.h
 *
 *  Created on: Oct 13, 2023
 *      Author: hp
 */

#ifndef APP_H_
#define APP_H_

/* Drivers I will use:
 * lED
 * CLCD
 * KPD
 * DC_MOTOR
 * */

#include "../01-LIB/STD_TYPES.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "../03-HAL/04-CLCD/CLCD_Interface.h"
#include "../03-HAL/05-KPD/KPD_Interface.h"
#include "../03-HAL/06-DC_MOTOR/DC_Motor_Interface.h"

#define LED_PIN      DIO_U8PIN3
#define MOTOR_PORT   DIO_u8PORTB
#define MOTOR_PIN1   DIO_U8PIN4
#define MOTOR_PIN2   DIO_U8PIN5
#define MOTOR_PIN3   DIO_U8PIN6
#define MOTOR_PIN4   DIO_U8PIN7

void app_init(void);
void Welcom_Page(void);
void Home_Page(void);
void Control_Choice(void);
void Control_LED_Choice(void);
void Control_DC_MOTOR_Choice(void);
void Control_DC_MOTOR_ON_Choice(void);
void DC_MOTOR_CW_ON(void);
void DC_MOTOR_CCW_ON(void);
void DC_MOTOR_OFF(void);
void Status_Choice(void);



#endif /* APP_H_ */
