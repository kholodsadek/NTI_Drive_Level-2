/*
 * WDT_Program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: hp
 */

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "WDT_Config.h"
#include "WDT_Interface.h"
#include "WDT_Private.h"

void WDT_Enable(void){
	/* Enabled WDT */
	SET_BIT(WDTCR, WDTCR_WDP0);
	SET_BIT(WDTCR, WDTCR_WDP1);
	SET_BIT(WDTCR, WDTCR_WDP2);
	SET_BIT(WDTCR, WDTCR_WDE);

}

void WDT_Disable(void){
	/* Disabled WDT */
	//WDTCR = (1<<WDTCR_WDP0) | (1<<WDTCR_WDE);
	SET_BIT(WDTCR, WDTCR_WDTOE);
	SET_BIT(WDTCR, WDTCR_WDE);
	/* Turn off WDT */
	WDTCR = 0x00;

}
