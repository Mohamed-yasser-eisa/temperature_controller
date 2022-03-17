/*
 * TC72_SPI.c
 *
 * Created: 6/6/2021 4:03:40 AM
 * Author : LENOVO
 */ 

#ifndef SPI_H_
#define SPI_H_


void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_transmit(char idata);
char SPI_recieve(void);




#endif 