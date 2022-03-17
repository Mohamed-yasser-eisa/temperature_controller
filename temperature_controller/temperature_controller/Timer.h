/*
 * Timer.h
 *
 * Created: 6/5/2021 5:24:26 AM
 *  Author: Mohamed Yasser
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "data_type.h"
/* this MISRA violation is dependent on compiler behavior*/
void timer2_CTC_init_interrupt_1ms(void);
void timer0_OC0_fastPWM(float8_ duty_cycle);
void stop_timer(void);

#endif /* TIMER_H_ */
