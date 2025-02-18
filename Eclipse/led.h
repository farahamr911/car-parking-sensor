/*
 * led.h
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */

#ifndef LED_H_
#define LED_H_

typedef enum
{
	LED_RED,LED_GREEN,LED_BLUE
}LED_ID;


#define LED_RED_PORT_ID     PORTC_ID
#define LED_RED_PIN_ID      PIN0_ID
#define LED_GREEN_PORT_ID   PORTC_ID
#define LED_GREEN_PIN_ID    PIN1_ID
#define LED_BLUE_PORT_ID    PORTC_ID
#define LED_BLUE_PIN_ID     PIN2_ID

#define LED_statues  1/*positive logic*/

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif /* LED_H_ */
