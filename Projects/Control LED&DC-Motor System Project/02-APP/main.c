/*
 * main.c
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */

#include "util/delay.h"
#include "app.h"

int main(void){
	app_init();

	//LCD Strings
	u8 wordCONTROL_PAGE[] = "CONTROL PAGE";
	u8 wordCONTROL_LED_PAGE[] = "CONTROL LED PAGE";
	u8 wordCONTROL_MOTOR_PAGE[] = "CONTROL MOTOR";
	u8 wordCONTROL_MOTOR_ON_PAGE[] = "CONTROL MOTOR ON";
	u8 wordSTATUS_PAGE[]  = "STATUS PAGE";
	u8 wordENTER[] = "ENTER: ";
	u8 wordLED_ON[]  = "LED_ON";
	u8 wordLED_OFF[] = "LED_OFF";
	u8 wordDC_MOTOR_OFF[] = "DC_MOTOR_OFF";
	u8 wordDC_MOTOR_ON_CW[] = "DC_MOTOR_ON_CW";
	u8 wordDC_MOTOR_ON_CCW[] = "DC_MOTOR_ON_CCW";

	Welcom_Page(); //Display welcome page
	CLCD_DisplayClear();

	while(1){
		Home_Page(); //Display Home page
		u8 KeypadEntry = KPD_GetPressedKey();
		if(KeypadEntry != 0){
			switch (KeypadEntry) {
				case '1': //Display Control Page
					CLCD_DisplayClear();

					CLCD_WriteString_Pos(wordCONTROL_PAGE,1,1);
					_delay_ms(500);
					CLCD_DisplayClear();

					Control_Choice(); //Control LED // Control Motor // Back to home page
					_delay_ms(1000);

					CLCD_DisplayClear();

					while(KeypadEntry != 'C'){
						CLCD_WriteString_Pos(wordCONTROL_PAGE,1,1);
						CLCD_WriteString_Pos(wordENTER,2,1);
						KeypadEntry = KPD_GetPressedKey();
						switch (KeypadEntry) {
							case '1': //Display LED_Control Page
								CLCD_DisplayClear();

								Control_LED_Choice();
								_delay_ms(1000);

								CLCD_DisplayClear();

								while(KeypadEntry != '*'){
									CLCD_WriteString_Pos(wordCONTROL_LED_PAGE,1,1);
									CLCD_WriteString_Pos(wordENTER,2,1);
									KeypadEntry = KPD_GetPressedKey();
									switch (KeypadEntry) {
										case '1': //LED_ON
											CLCD_DisplayClear();

											LED_voidON(LED_PIN);

											CLCD_WriteString_Pos(wordLED_ON,1,1);
											_delay_ms(500);
											CLCD_DisplayClear();

											break;
										case '2': //LED_OFF
											CLCD_DisplayClear();

											LED_voidOFF(LED_PIN);

											CLCD_WriteString_Pos(wordLED_OFF,1,1);
											_delay_ms(500);
											CLCD_DisplayClear();
											break;
										case '*': //return to control page
											CLCD_DisplayClear();
											Control_Choice();
											_delay_ms(1000);
											CLCD_DisplayClear();
											break;
										case '=': ; //return Led Control page
											CLCD_DisplayClear();
											Control_LED_Choice();
											_delay_ms(1000);
											CLCD_DisplayClear();
											break;
										default:
											break;
									}
								}
								CLCD_DisplayClear();
								break;
							case '2': //Display Motor_Control Page
								CLCD_DisplayClear();

								Control_DC_MOTOR_Choice();
								_delay_ms(1000);

								CLCD_DisplayClear();

								while(KeypadEntry != '*'){
									CLCD_WriteString_Pos(wordCONTROL_MOTOR_PAGE,1,1);
									CLCD_WriteString_Pos(wordENTER,2,1);
									KeypadEntry = KPD_GetPressedKey();
									switch (KeypadEntry) {
										case '1': //Display MOTOR_ON Page
											CLCD_DisplayClear();

											Control_DC_MOTOR_ON_Choice();
											_delay_ms(1000);

											CLCD_DisplayClear();

											while(KeypadEntry != '*'){
												CLCD_WriteString_Pos(wordCONTROL_MOTOR_ON_PAGE,1,1);
												CLCD_WriteString_Pos(wordENTER,2,1);
												KeypadEntry = KPD_GetPressedKey();
												switch (KeypadEntry) {
													case '1': //DC_MOTOR_CW_ON
														CLCD_DisplayClear();

														DC_MOTOR_CW_ON();

														CLCD_WriteString_Pos(wordDC_MOTOR_ON_CW,1,1);
														_delay_ms(500);
														CLCD_DisplayClear();
														break;
													case '2': //DC_MOTOR_CCW_ON
														CLCD_DisplayClear();

														DC_MOTOR_CCW_ON();

														CLCD_WriteString_Pos(wordDC_MOTOR_ON_CCW,1,1);
														_delay_ms(500);
														CLCD_DisplayClear();
														break;
													case '*': //return to Control Page
														CLCD_DisplayClear();
														Control_Choice();
														_delay_ms(1000);
														CLCD_DisplayClear();
														break;
													case '=': //return to DC_Motor_ON Page
														CLCD_DisplayClear();
														Control_DC_MOTOR_ON_Choice();
														_delay_ms(1000);
														CLCD_DisplayClear();
														break;
													default:
														break;
												}
											}
											break;
										case '2': //MOTOR_OFF
											CLCD_DisplayClear();

											DC_MOTOR_OFF();

											CLCD_WriteString_Pos(wordDC_MOTOR_OFF,1,1);
											_delay_ms(500);
											CLCD_DisplayClear();
											break;
										case '*': //return to control page
											CLCD_DisplayClear();
											Control_Choice();
											_delay_ms(1000);
											CLCD_DisplayClear();
											break;
										case '=': ; //return DC-Motor Control page
											CLCD_DisplayClear();
											Control_DC_MOTOR_Choice();
											_delay_ms(1000);
											CLCD_DisplayClear();
											break;
										default:
											break;
									}
								}
								CLCD_DisplayClear();
								break;
							case '=': //return Control page
								CLCD_DisplayClear();
								Control_Choice();
								_delay_ms(1000);
								CLCD_DisplayClear();
								break;
							case 'C': //return to Home page
								break;
							default:
								break;
						}
					}
					CLCD_DisplayClear();
					break;
				case '2': //Display Status Page
					CLCD_DisplayClear();

					CLCD_WriteString_Pos(wordSTATUS_PAGE,1,1);
					_delay_ms(1000);
					CLCD_DisplayClear();
					while(KeypadEntry != '*'){
						KeypadEntry = KPD_GetPressedKey();
						switch (KeypadEntry) {
							case '*':
								//return to Home Page
								break;
							default:
								Status_Choice();
								break;
						}
					}
					CLCD_DisplayClear();
					break;
				default:
					break;
			}
		}
	}
}
