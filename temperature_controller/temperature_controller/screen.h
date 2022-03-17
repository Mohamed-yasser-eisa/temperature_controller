/*
 * screen.h
 *
 * Created: 6/8/2021 11:29:02 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef SCREEN_H_
#define SCREEN_H_
#include "data_type.h"
void display_on(void);
void welcome(void);
void IDLE_screen(uint8_ set_temp,uint8_ crt_temp, char *sys_sts );
void enter_temp(void);
void error_state_dis(void);
void current_temp_dis(uint8_ temp);



#endif /* SCREEN_H_ */
