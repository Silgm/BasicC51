#include "delay.h"

void delay_ms(uint16_t ms)
{
	unsigned char i = 0;
	for (; ms; --ms)
		for (i = 0; i < DELAY_FACTOR; ++i);
}

