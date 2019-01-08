#include <reg52.h>
#include "delay.h"
#include "gpio.h"
#include "lcd1602.h"
#include <stdio.h>
/*
#include "binary.h"

char buff[32] = "";

const char heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};
*/

void main()
{	
	/*
	Lcd1602 lcd;
	Lcd1602_Create(&lcd, P2_5, P2_4, P2_3, P2_2, P2_1, P2_0);
	Lcd1602_init(&lcd);
	
	Lcd1602_createChar(&lcd, 0, heart);
	
	Lcd1602_setCursor(&lcd, 0, 0);
	Lcd1602_print(&lcd, "I ");
	Lcd1602_showChar(&lcd, 0);
	Lcd1602_print(&lcd, " C51");
	*/
	
	for (;;)
	{
	}
}

