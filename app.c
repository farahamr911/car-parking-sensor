/*
 * app.c
 *
 *  Created on: Oct 14, 2024
 *      Author: farah
 */
#include <avr/io.h>
#include"buzzer.h"
#include"icu.h"
#include"ultrasonic.h"
#include"led.h"
#include"lcd.h"
#include"std_types.h"

int main(void)
{
	Ultrasonic_init();
	LCD_init();
	LEDS_init();
	Buzzer_init();

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	uint16 dis = Ultrasonic_readDistance();
	LCD_moveCursor(0,1);
	LCD_displayString("Distance=");
	LCD_moveCursor(0,10);
	LCD_intgerToString(dis);
	LCD_moveCursor(0,13);
	LCD_displayString("cm");
	while(1)
	{
		dis=Ultrasonic_readDistance();
		if(dis<=5)
		{
			Buzzer_on();
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,11);
			LCD_displayString("  ");
			LCD_moveCursor(1,6);
			LCD_displayString("Stop");
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
		}
		else if((dis>=6)&&(dis<=10))
		{
			if(dis<10)
			{
				Buzzer_off();
				LCD_moveCursor(0,10);
				LCD_intgerToString(dis);
				LCD_moveCursor(0,11);
				LCD_displayString("  ");
				LCD_moveCursor(1,6);
				LCD_displayString("                   ");
				LED_on(LED_RED);
				LED_on(LED_GREEN);
				LED_on(LED_BLUE);
			}
			Buzzer_off();
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,12);
			LCD_displayString(" ");
			LCD_moveCursor(1,6);
			LCD_displayString("                   ");
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
		}
		else if((dis>=11)&&(dis<=15))
		{
			Buzzer_off();
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,12);
			LCD_displayString(" ");
			LCD_moveCursor(1,6);
			LCD_displayString("                   ");
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else if((dis>=16)&&(dis<=20))
		{
			Buzzer_off();
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,12);
			LCD_displayString(" ");
			LCD_moveCursor(1,6);
			LCD_displayString("                   ");
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else if(dis>20)
		{
			Buzzer_off();
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,12);
			LCD_displayString(" ");
			LCD_moveCursor(1,6);
			LCD_displayString("                   ");
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}

	}

}
