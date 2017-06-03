#include <mega16.h>
#include <delay.h>

//-- Atmega16 --
//-- Fontions pour utiliser l'USART --

void init_USART();
void envoi_USART(unsigned char data);
char recep_USART();