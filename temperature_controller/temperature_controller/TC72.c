#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "TC72.h"

void TC72Init(void)
{
	SPI_MasterInit();
	PORTB|=(1<<4);
	/*Select Control Register*/
	SPI_transmit(0x80);
	/*Select Continuous temperature Conversion*/
	SPI_transmit(0x04);
	PORTB&=~(1<<4);
	_delay_ms(150);
}

char TC72_GetReading(void)
{
		  char msb;
		  PORTB|=(1<<4);
		  /*Read the MSB*/
		  SPI_transmit(0x02);
		  /*Issue one more clock frame
		  to force data out*/
		  SPI_transmit(0x00);
		  PORTB&=~(1<<4);
		  _delay_ms(1);
		  msb=SPI_recieve();
		  return msb;
}
