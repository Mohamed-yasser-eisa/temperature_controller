/*
 * Timer.c
 *
 * Created: 6/5/2021 5:24:46 AM
 *  Author: Mohamed Yasser
 */ 

#include "Timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#define REGISTER_SIZE          8
#define SET_BIT(reg,bit)       reg|=(1<<bit)
#define CLR_BIT(reg,bit)       reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)       reg^=(1<<bit)
#define READ_BIT(reg,bit)      ((reg>>bit)&1)
#define IS_BIT_SET(reg,bit)    ((reg>>bit)&1)
#define IS_BIT_CLR(reg,bit)    !((reg>>bit)&1)
#define ROR(reg,num)           reg=((reg>>num)|(reg<<(REGISTER_SIZE-num)))
#define ROL(reg,num)           reg=((reg<<num)|(reg>>(REGISTER_SIZE-num)))



void timer2_CTC_init_interrupt_1ms(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR2,WGM21);
	/* load a value in OCR2 */
	OCR2=125;
	/* select timer clock to be (8000000/1024) */
	SET_BIT(TCCR2,CS22);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE2);
}

void timer0_OC0_fastPWM(float8_ duty_cycle)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode in timer0*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR2 */
	OCR0=(uint8_)((duty_cycle/10)*254);
	
	
	
	/* select wave frequency = (8MHz/8*256) */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	/*SET_BIT(TCCR2,CS22);*/
	
	/* clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)*/
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}



void stop_timer(void)
{
	CLR_BIT(TIMSK,OCIE2);
	CLR_BIT(DDRB,3);
}
