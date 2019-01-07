#include <reg52.h>
#include "delay.h"
#include "gpio.h"
#include "lcd1602.h"

void main()
{	
	Lcd1602 lcd;
	Lcd1602_Create(&lcd, P2_5, P2_4, P2_3, P2_2, P2_1, P2_0);
	Lcd1602_init(&lcd);
	Lcd1602_print(&lcd, "Hello, World");
	//Lcd1602_cursor(&lcd);
	for (;;)
	{
		//Lcd1602_print(&lcd, "Hello, World");
	}
}

