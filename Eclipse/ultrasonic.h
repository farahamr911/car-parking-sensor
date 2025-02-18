/*
 * ultrasonic.h
 *
 *  Created on: Oct 14, 2024
 *      Author: farah
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
#include "gpio.h"

#define Echo_Port_ID     PORTD_ID
#define Trigger_Port_ID  PORTD_ID

#define Echo_Pin_ID     PIN6_ID
#define Trigger_Pin_ID  PIN7_ID

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
