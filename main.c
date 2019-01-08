#include <reg52.h>
#include "delay.h"
#include "gpio.h"
#include "lcd1602.h"
#include <stdio.h>

#include "binary.h"
#include "at24c02.h"

char buff[32] = "";

void main()
{
	uint8_t dat = 0;
	At24c02 rom;
	Lcd1602 lcd;
	
	Lcd1602_create(&lcd, P2_5, P2_4, P2_3, P2_2, P2_1, P2_0);
	At24c02_create(&rom, P1_2, P1_1, AT24C02_ADDRESS_A2A1A0_000);
	
	At24c02_init(&rom);
	//At24c02_writeByte(&rom, 0x10, (uint8_t)99);
	dat = At24c02_readByte(&rom, 0x10);
	
	
	Lcd1602_init(&lcd);
	Lcd1602_setCursor(&lcd, 0, 0);
	
	sprintf(buff, "Int:%d", (int)dat);
	Lcd1602_print(&lcd, buff);
	
	
	for (;;);
}

/*
void main()
{
	uint8_t dat;
	Lcd1602 lcd;
	At24c02 rom;
	
	Lcd1602_Create(&lcd, P2_5, P2_4, P2_3, P2_2, P2_1, P2_0);
	Lcd1602_init(&lcd);
	
	At24c02_create(&rom, P1_2, P1_1, AT24C02_ADDRESS_A2A1A0_000);
	At24c02_init(&rom);
	
	//At24c02_writeByte(&rom, 10, (uint8_t)100);
	//delay_ms(1);
	dat = At24c02_readByte(&rom, 10);
	
	sprintf(buff, "%d", (int)dat);
	
	Lcd1602_print(&lcd, buff);
	

	for(;;);
}
*/
/*
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


void main()
{	
	
	Lcd1602 lcd;
	Lcd1602_Create(&lcd, P2_5, P2_4, P2_3, P2_2, P2_1, P2_0);
	Lcd1602_init(&lcd);
	/*
	Lcd1602_createChar(&lcd, 0, heart);
	
	Lcd1602_setCursor(&lcd, 0, 0);
	Lcd1602_print(&lcd, "I ");
	Lcd1602_showChar(&lcd, 0);
	Lcd1602_print(&lcd, " C51");
	*/
	/*
	for (;;)
	{
		if (digitalRead(P1_0) == HIGH)
		{
			Lcd1602_setCursor(&lcd, 0, 0);
			Lcd1602_print(&lcd, "HIGH");
		}
		else
		{
			Lcd1602_setCursor(&lcd, 0, 0);
			Lcd1602_print(&lcd, "LOW ");		
		}
	}
}
*/
