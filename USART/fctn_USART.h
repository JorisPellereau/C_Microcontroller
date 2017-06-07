#include <mega16.h>
#include <stdlib.h>
#include <stdio.h>
#include <delay.h>
#include <math.h>

//-- Atmega16 --
//-- Fontions pour utiliser l'USART --

void init_USART();
void envoi_USART(unsigned char data);
char recep_USART();
void buffer_flush(void);