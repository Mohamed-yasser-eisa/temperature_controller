/*
 * system_state.h
 *
 * Created: 6/8/2021 11:32:53 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef SYSTEM_STATE_H_
#define SYSTEM_STATE_H_
#include "data_type.h"
/* this MISRA violation is dependent on compiler behavior*/
void STANDBY(void);
void NORMAL_state(uint8_ set_temp,uint8_ cur_temp);




#endif /* SYSTEM_STATE_H_ */
