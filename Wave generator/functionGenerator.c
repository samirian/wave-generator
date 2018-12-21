/*
 * functionGenerator.c
 *
 * Created: 12/21/2018 9:47:41 AM
 *  Author: Samir
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "UART.h"

int sine[256];

void generator_init(){
	double inc = 24/17;//     360/255 = 24/17
	for (int i = 0 ; i < 256 ;i++)
	{
		sine[i] =(int) (sin(inc*i)*256);
	}
}

void pulseGenerator(volatile uint8_t *PORT, int frequeny){
	*PORT = 0x00;
	for (int i = 0 ; i < 128 ;i++){
		if(i%20 == 0){
			*PORT = *PORT + 1;
		}
	}
	*PORT = 0xff;
	for (int i=0; i<128 ;i++){
		if(i%20 == 0){
			*PORT = *PORT - 1;
		}
	}
}

void stairGenerator(volatile uint8_t *PORT, int frequeny){
	for (int i = 0 ; i < 256 ;i++){
		_delay_us(100);
		*PORT = i;
	}
}

void sineGenerator(volatile uint8_t *PORT, int frequeny){
	for (int i = 0 ; i < 256 ;i++){
		_delay_us(100);
		*PORT = sine[i];
	}
}