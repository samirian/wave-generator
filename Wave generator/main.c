/*
 * GccApplication2.c
 *
 * Created: 12/20/2018 11:17:21 PM
 * Author : Samir
 */ 

#include <avr/io.h>
#include "UART.h"
#define F_CPU 8000000ul
#include <util/delay.h>
#include "functionGenerator.h"


int main(void)
{
    /* Replace with your application code */
	DDRB = 0xff;
	uart_init();
	uart_transmit('a');
    while (1) 
    {
		//pulseGenerator(&PORTB, 5);
		//stairGenerator(&PORTB,5);
		sineGenerator(&PORTB,5);
    }
}

