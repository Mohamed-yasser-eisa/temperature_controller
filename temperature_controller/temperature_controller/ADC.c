/*
 * ADC.c
 *
 * Created: 6/5/2021 10:20:15 PM
 *  Author: Mohamed Yasser
 */ 

#include "ADC.h"

#include <avr/io.h>
#include "Std_DIO_macros.h"

void ADC_init(void)
{
	/* configure AVCC as reference voltage with external capacitor on AREF pin  */
	SET_BIT(ADMUX,REFS0);
	/* enable ADC */
	SET_BIT(ADCSRA,ADEN);
	/* choose prescaler number to adjust ADC clock*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}

uint16_ ADC_read(void)
{
	uint16_ read_val;
	/* start ADC conversion, when finish it will be set to zero again */
	SET_BIT(ADCSRA,ADSC);
	/* wait for the ADC conversion to end  (polling) */
	while(IS_BIT_CLR(ADCSRA,ADIF));
	/* clear ADIF, flag interrupt to zero */
	SET_BIT(ADCSRA,ADIF);
	/* read digital value */
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
}


