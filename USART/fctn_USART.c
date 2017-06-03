#include <mega16.h>
#include <delay.h>
#include "fctn_USART.h"

//-- Atmega16 --
//-- Fontions pour utiliser l'USART --

void init_USART() {
      
     UCSRA = 0x00;
     UCSRB = 0x18;  // TX en Rx en 
     UCSRC = 0x86;
     UCSRC = 0x86;
     UBRRH = 0x0;//(foscl/16/baud - 1)>>8; //0x00;
     UBRRL = 0x19;       
}


void envoi_USART(unsigned char data) {
     while ( !( UCSRA & (1<<UDRE)) );
     //while( (UCSRA & 0x20) != 0x20);       // Attente buffer empty avant envoyer DATA
     UDR = data;                        // Envoie de la data par ecriture de UDR
}


char recep_USART() {
     while( !(UCSRA & (1 << RXC)) );          // Attente que le buffer soit rempli d'une data non lu
     return UDR;
}