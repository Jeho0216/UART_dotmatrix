/*
 * hc595.h
 *
 *  Created on: 2019. 4. 29.
 *      Author: kccistc
 */

#ifndef HC595_H_
#define HC595_H_

#include "stm32f1xx_hal.h"

#define DATA 		GPIO_PIN_15
#define DATA_PORT	GPIOB
#define LATCH_CLOCK GPIO_PIN_12
#define LATCH_PORT	GPIOB
#define SHIFT_CLOCK	GPIO_PIN_13
#define SHIFT_PORT	GPIOB

void shiftClock(void);
void LatchClock(void);
void ByteDataWrite(uint8_t data);
void WordDataWrite(uint16_t data);

#endif /* 74HC595_H_ */
