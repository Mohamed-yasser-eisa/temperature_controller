/*
 * PWM.c
 *
 * Created: 6/9/2021 8:44:49 AM
 *  Author: Mohamed Yasser
 */ 
#include "PWM.h"
#include "Timer.h"


void PWM_generate(float8_ PWM_duty_cycle)
{
	timer0_OC0_fastPWM( PWM_duty_cycle);
}
