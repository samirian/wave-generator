#ifndef _UART_H_
#define _UART_H_
#define F_CPU 8000000ul
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

void uart_init (void);
void uart_transmit (unsigned char data);
unsigned char uart_recieve (void);

#endif