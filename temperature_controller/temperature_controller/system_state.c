/*
 * system_state.c
 *
 * Created: 6/8/2021 11:33:14 PM
 *  Author: Mohamed Yasser
 */ 

#include "system_state.h"
#include "screen.h"

void STANDBY(void)
{
	
	IDLE_screen((uint8_)25,(uint8_)25,"STANDBY");
}
void NORMAL_state(uint8_ set_temp,uint8_ cur_temp )
{
	IDLE_screen(set_temp,cur_temp,"NORMAL");
}
