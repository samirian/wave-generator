/*
 * uart.c
 *
 * Created: 12/21/2018 8:11:58 AM
 *  Author: Samir
 */ 
#include "UART.h"
#include <avr/io.h>
#include <avr/interrupt.h>


void uart_init (void)
{
	UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
	UBRRL = BAUDRATE;                           // set baud rate
	UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter
	UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format
}

// function to send data
void uart_transmit (unsigned char data)
{
	while (!( UCSRA & (1<<UDRE)));                // wait while register is free
	UDR = data;                                   // load data in the register
}

// function to receive data
unsigned char uart_recieve (void)
{
	while(!(UCSRA) & (1<<RXC));                   // wait while data is being received
	return UDR;                                   // return 8-bit data
}
