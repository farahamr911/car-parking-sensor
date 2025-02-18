/*
 * ultrasonic.c
 *
 *  Created on: Oct 14, 2024
 *      Author: farah
 */

#include "icu.h"
#include"ultrasonic.h"
#include<util/delay.h>
#include"std_types.h"
#include"led.h"

uint16 g_edgeCount = 0;
uint16 g_timeEcho = 0;

ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};

void Ultrasonic_init(void)
{
	ICU_init(&ICU_Configurations);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
//	GPIO_setupPinDirection(Echo_Port_ID,Echo_Pin_ID,PIN_INPUT);
	GPIO_setupPinDirection(Trigger_Port_ID,Trigger_Pin_ID,PIN_OUTPUT);
	GPIO_writePin(Trigger_Port_ID, Trigger_Pin_ID, 0);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(Trigger_Port_ID, Trigger_Pin_ID, 1);
	_delay_us(10);
	GPIO_writePin(Trigger_Port_ID, Trigger_Pin_ID, 0);
}

uint16 Ultrasonic_readDistance(void)
{
	uint16 distance;
	Ultrasonic_Trigger();
	distance=(g_timeEcho/117.6)+1;
	return distance;
}

void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeEcho = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount=0;

	}
}

