/*
 * interrupt.c
 *
 * Created: 6/9/2021 6:56:12 AM
 *  Author: Mohamed Yasser
 */ 
#include <avr/interrupt.h>
#include "interrupt.h"
#include <avr/io.h>
#include "Std_DIO_macros.h"
#include "Timer.h"

void external_intrrupt2(void)
{
	sei();
	CLR_BIT(DDRB,2);
	CLR_BIT(MCUCSR,ISC2);
	SET_BIT(GICR,INT2);
	
}
void interrupt_1ms(void)
{
	 timer2_CTC_init_interrupt_1ms();
}
void diable_interrupts(void)
{
	cli();
	CLR_BIT(GICR,INT2);
	CLR_BIT(ADCSRA,ADEN);
	
	stop_timer();
}