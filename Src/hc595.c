/*
 * hc595.c
 *
 *  Created on: 2019. 4. 29.
 *      Author: kccistc
 */
#include <hc595.h>
#include "stm32f1xx_hal.h"

void shiftClock(void)
{
	HAL_GPIO_WritePin(SHIFT_PORT, SHIFT_CLOCK, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SHIFT_PORT, SHIFT_CLOCK, GPIO_PIN_RESET);
}

void LatchClock(void)
{
	HAL_GPIO_WritePin(LATCH_PORT, LATCH_CLOCK, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LATCH_PORT, LATCH_CLOCK, GPIO_PIN_RESET);
}

void ByteDataWrite(uint8_t data)
{
	for (uint8_t i=0; i<8; i++)
	{
		if (data & 0x80)
		{
			HAL_GPIO_WritePin(DATA_PORT, DATA, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(DATA_PORT, DATA, GPIO_PIN_RESET);
		}

		shiftClock();
		data = data << 1;
	}
	LatchClock();
}

void WordDataWrite(uint16_t data)
{
	for (uint8_t i=0; i<16; i++)
	{
		if (data & 0x8000)
		{
			HAL_GPIO_WritePin(DATA_PORT, DATA, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(DATA_PORT, DATA, GPIO_PIN_RESET);
		}

		shiftClock();
		data = data << 1;
	}
	LatchClock();
}
