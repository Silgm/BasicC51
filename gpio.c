#include "gpio.h"
#include <reg52.h>

#define PIN_TO_MASK(p) 	(0x01<<(p%8))
#define PIN_TO_PORT(p)	(p>>3)

void digitalWrite(Pin pin, uint8_t val)
{
	uint8_t bitMask = PIN_TO_MASK(pin);
	Port port = PIN_TO_PORT(pin);
	
	if (port == PORT_0)
	{
		if(val)
			P0 |= bitMask;
		else
			P0 &= ~(bitMask);
	}
	else if (port == PORT_1)
	{
		if(val)
			P1 |= bitMask;
		else
			P1 &= ~(bitMask);
	}
	else 
	{
		if(val)
			P2 |= bitMask;
		else
			P2 &= ~(bitMask);
	}
}


uint8_t digitalRead(Pin pin)
{
	uint8_t bitMask = PIN_TO_MASK(pin);
	Port port = PIN_TO_PORT(pin);
	
	if (port == PORT_0)
	{
		if(P0 & bitMask)
			return HIGH;
		else
			return LOW;
	}
	else if (port == PORT_1)
	{
		if(P1 & bitMask)
			return HIGH;
		else
			return LOW;
	}
	else 
	{
		if(P2 & bitMask)
			return HIGH;
		else
			return LOW;
	}
}