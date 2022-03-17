/*
 * screen.c
 *
 * Created: 6/8/2021 11:29:18 PM
 *  Author: Mohamed Yasser
 */ 
#define F_CPU 8000000ul
#include <avr/delay.h>
#include "LCD.h"
#include "TC72.h"
#include "screen.h"

/* Initialize LCD */
void display_on()
{
	LCD_vInit();
}

void welcome()
{
	uint8_ move=0;
	uint8_ iteration=0;
	for (iteration=1; iteration<=3;iteration++)
	{
		
		for (move=1; move < 11; move++ )
		{
			LCD_clearscreen();
			LCD_movecursor(1,move);
			LCD_vSend_string("WELCOME");
			_delay_ms(100);
		}
		for (move=9; move > 0; move-- )
		{
			LCD_clearscreen();
			LCD_movecursor(1,move);
			LCD_vSend_string("WELCOME");
			_delay_ms(100);
		}
	}
}

void IDLE_screen(uint8_ set_temp, uint8_ crt_temp, char *sys_sts )
{
	LCD_clearscreen();
	LCD_movecursor(1,1);
	LCD_vSend_string("SET:");
	LCD_movecursor(1,5);
	LCD_vSend_char((set_temp/10)+48);
	LCD_movecursor(1,6);
	LCD_vSend_char((set_temp%10)+48);
	LCD_movecursor(1,11);
	LCD_vSend_string("CRT:");
	LCD_movecursor(1,15);
	LCD_vSend_char((crt_temp/10)+48);
	LCD_movecursor(1,16);
	LCD_vSend_char((crt_temp%10)+48);
	LCD_movecursor(2,1);
	LCD_vSend_string("STATE:");
	LCD_movecursor(2,7);
	LCD_vSend_string(sys_sts);
	/*_delay_ms(100);*/
}

void enter_temp(void)
{
	LCD_clearscreen();
	LCD_movecursor(1,1);
	LCD_vSend_string("Enter Temperature");
	
}

void error_state_dis(void)
{
	LCD_clearscreen();
	LCD_movecursor(1,1);
	LCD_vSend_string("ERROR STATE");
}
void current_temp_dis(uint8_ temp)
{
	LCD_movecursor(1,15);
	LCD_vSend_char((temp/10)+48);
	LCD_movecursor(1,16);
	LCD_vSend_char((temp%10)+48);
}