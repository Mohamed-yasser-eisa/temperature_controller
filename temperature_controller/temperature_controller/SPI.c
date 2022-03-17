/*
 * TC72_SPI.c
 *
 * Created: 6/6/2021 4:03:40 AM
 * Author : LENOVO
 */ 


#include <avr/io.h> 
#include "SPI.h"

void SPI_MasterInit(void)
{   
	DDRB |=0xB0;             // B5 ,B4 and B7 are configured as output (MOSI , SS',SCK)
	SPCR = 0x57;               //SPI is Enable , LSB is transmitted first , Master SPI , SCK is low when idle,Sample in Leading Edge, FOSC/128.
	SPSR = 0x00;               //Flag is reset , and FOSC/128 is used .
}



void SPI_SlaveInit(void)
{   
	DDRB &= (~(1<<6)) ;    // B6 are configured as input (MISO)
	SPCR=0x47;            //SPI is Enable , LSB is transmitted first,  Slave SPI ,SCK is low when idle,Sample in Leading Edge, FOSC/128.
	SPSR=0x00;            //Flag is reset , and FOSC/128 is used .
}


void SPI_transmit(char idata)
{
	SPDR=idata;                     //Send input data to the Data register 
	while( (SPSR&&(1<<7))==0 ) ;      // While Transmission not completed wait .  (To aviod overlapping of data transmission )
	
}



char SPI_recieve(void)
{   
	while( (SPSR && (1<<7))==0 ) ;   // While Transmission not completed wait untill it's complete 
	return SPDR;                 //Return the received data found in Datareister .
}

