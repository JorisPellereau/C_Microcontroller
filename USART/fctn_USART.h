#include <mega16.h>

//-- Atmega16 --
//-- Fontions pour utiliser l'USART --

void init_USART();
void envoi_USART(unsigned char data);
char recep_USART();
void buffer_flush(void);