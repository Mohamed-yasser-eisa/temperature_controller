/*
 * final_project.c
 *
 * Created: 6/8/2021 10:07:09 PM
 * Author : Mohamed Yasser
 */
#define F_CPU 8000000ul
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <string.h>
#include "Std_DIO_macros.h"
#include "data_type.h"
#include "TC72.h"
#include "screen.h"
#include "interrupt.h"
#include "PWM.h"
#include "system_state.h"
#include "potentiometer.h"

volatile uint8_ current_temp=25;
volatile uint8_ exit_loop=0;
volatile uint32_ minutes3=0;
uint8_  set_temp=25;



int main(void)
{

    TC72Init();
	display_on();
    keypad_vInit();
    potentiometer_init();
    welcome();
    external_intrrupt2();


    uint8_ error_state=0;
    float8_ Vt=0;
    float8_ Vr=0;
    float8_ duty_cycle=0;
    uint8_ temp=0;
    uint8_ flag=0;
    uint8_ loop1=1;
    uint8_ error1=0;
	uint8_ normal1=0;
	uint8_ operational=0;
	


    while (1)
    {
        /* standby mode */
        if (loop1==1)
        {
            IDLE_screen(set_temp,current_temp,"STANDBY");
            loop1=0;
        }


        if ( exit_loop=='#' )
        {
            /* enter operational mode */
            enter_temp();
            set_temp=input_keypad();
            exit_loop=0;
            interrupt_1ms();
            loop1=1;
            error1=1;
			normal1=1;
			operational=1;
			
            while(1) /* operational mode: */
            {

                if (error_state==0 && loop1==1)
                {
                    IDLE_screen(set_temp,current_temp,"OPERATION");
                    loop1=0;
					normal1=1;
					operational=0;
					
                }
                else
                {
					/* change current temperature reading on display  */
                    current_temp_dis(current_temp);
					
                }
				
				
                if (set_temp <= current_temp)
                {
                    Vt=0;
                }
                else
                {
                    Vt=( ( (float8_)(set_temp - current_temp) / 100.0) *10.0 );
                }
                Vr=(float8_)potentiometer_read();
                duty_cycle = (( ((Vr*2.0)/10.0)*Vt)/10);
                PWM_generate(duty_cycle);
				
                /* 6-system state */
                if ( (current_temp > set_temp) && ((current_temp - set_temp)<=5) )
                {
                    /* enter normal state */
                    PWM_generate(0.0); /* zero duty cycle*/
					if (normal1==1)
					{
						NORMAL_state(set_temp,current_temp);
						normal1=0;
					}
					operational=1;
					minutes3=0;
                }
                else if ( (current_temp < set_temp) && ((set_temp - current_temp)<=5) )
                {
                    /* enter normal state */
                    PWM_generate(0.0); /* zero duty cycle*/
					if (normal1==1)
					{
						NORMAL_state(set_temp,current_temp);
						normal1=0;
					}
					operational=1;
					minutes3=0;
                }
				
                else if ( (current_temp > set_temp) && ( (current_temp - set_temp) >10 ))
                {
                    /* enter error state */
                    PWM_generate(0.0); /* zero duty cycle*/
                    diable_interrupts();
					
                    if (error1==1)
                    {
                         error_state_dis();
                         error1=0;
                    }

                    error_state=1;
                }
				
                else if ( (set_temp > current_temp) && ((set_temp - current_temp)>5) )
                {

                    if (minutes3 > 18000)
                    {
                        /* error state */

                        PWM_generate(0.0); /* zero duty cycle*/
                        diable_interrupts();
                        error_state_dis();
                        minutes3=0;
                        error_state=1;
                    }
					if (operational==1)
					{
						loop1=1;
						error_state=0;
						
					}	
					
                }
                else if (exit_loop=='#')
                {
                    exit_loop=0;
                    loop1=1;
                    break;
                }
				else if ( (current_temp > set_temp) && ((current_temp - set_temp)>5)  )
				{
					if (operational==1)
					{
						loop1=1;
						error_state=0;
						
					}
				}

            }

        }


    }
	
}

ISR(TIMER2_COMP_vect)
{
    static uint8_ notify200ms=0;
    minutes3++;
    notify200ms++;
    if (notify200ms == 200)
    {
        current_temp = TC72_GetReading();
    }
}

ISR(INT2_vect)
{
    exit_loop='#';
}
