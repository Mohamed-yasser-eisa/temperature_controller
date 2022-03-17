/*
 * potentiometer.c
 *
 * Created: 6/9/2021 8:35:34 AM
 *  Author: Mohamed Yasser
 */ 
#include "ADC.h"
#include "potentiometer.h"


void potentiometer_init(void)
{
	ADC_init();
}

uint16_ potentiometer_read(void)
{
	return ADC_read();
}
