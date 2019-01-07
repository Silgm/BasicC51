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

void digitalWritePort(Port port, uint8_t val)
{
	if (port == PORT_0)
		P0 = val;
	else if (port == PORT_1)
		P1 = val;
	else 
		P2 = val;
}

uint8_t digitalReadPort(Port port)
{
	if (port == PORT_0)
		return P0;
	else if (port == PORT_1)
		return P1;
	else 
		return P2;
}

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
	uint8_t value = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		digitalWrite(clockPin, HIGH);
		if (bitOrder == LSBFIRST)
			value |= digitalRead(dataPin) << i;
		else
			value |= digitalRead(dataPin) << (7 - i);
		digitalWrite(clockPin, LOW);
	}
	return value;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
	uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST)
			digitalWrite(dataPin, !!(val & (1 << i)));
		else	
			digitalWrite(dataPin, !!(val & (1 << (7 - i))));
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}

