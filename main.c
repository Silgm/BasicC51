#include <reg52.h>
#include "delay.h"
#include "gpio.h"

void main()
{	
	for(;;)
	{
		digitalWrite(P1_1, HIGH);
		delay_ms(100);
		digitalWrite(P1_1, LOW);
		delay_ms(100);
	}
}

