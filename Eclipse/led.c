/*
 * led.c
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */


#include "gpio.h"
#include "led.h"

void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);
#if(LED_statues==0)
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, 1);
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, 1);
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, 1);
#else
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, 0);
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, 0);
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, 0);
#endif
}

void LED_on(LED_ID id)
{
#if(LED_statues==0)
	switch(id)
	{
	case LED_RED:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, 0);
		break;
	case LED_GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, 0);
		break;
	case LED_BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, 0);
		break;
	}
#else
	switch(id)
	{
	case LED_RED:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, 1);
		break;
	case LED_GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, 1);
		break;
	case LED_BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, 1);
		break;
	}
#endif
}

void LED_off(LED_ID id)
{
#if(LED_statues==0)
	switch(id)
	{
	case LED_RED:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, 1);
		break;
	case LED_GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, 1);
		break;
	case LED_BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, 1);
		break;
	}
#else
	switch(id)
	{
	case LED_RED:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, 0);
		break;
	case LED_GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, 0);
		break;
	case LED_BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, 0);
		break;
	}
#endif
}
