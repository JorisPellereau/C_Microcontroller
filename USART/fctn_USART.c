#include <mega16.h>
#include <stdlib.h>
#include <stdio.h>
#include <delay.h>
#include <math.h>
#include "fctn_USART.h"

//-- Atmega16 --
//-- Fontions pour utiliser l'USART --

void init_USART(unsigned int baud, unsigned int fosc) {
      
     unsigned int ub;
     char ubL;
     ub = fosc/(16*baud) -1;
     ubL = ub & 0xFF;
     UCSRA = 0x00;
     UCSRB = 0x98; // 98 : it RX en, RX TX en // TX en Rx en  àx18 : ok
     UCSRC = 0x86;
     UCSRC = 0x86;
     UBRRH = 0x0;//(foscl/16/baud - 1)>>8; //0x00;
     //UBRRL = 0x19;     
     //UBRRH = (ubrr >> 8) & 0xFF;
    // UBRRL = 0;
     UBRRL = 0x19;//ubL;       
}      


void envoi_USART(unsigned char data) {
     while ( !( UCSRA & ( 1<< UDRE)) );
     UDR = data;                             // Envoie de la data par ecriture de UDR
}

char recep_USART() {
     while( !(UCSRA & (1 << RXC)) );         // Attente que le buffer soit rempli d'une data non lu
     return UDR;
}

void buffer_flush(void){                     // Permet de vider le buffer de reception (RXC => 0)
     unsigned char dummy;
     while ( UCSRA & (1 << RXC) ) dummy = UDR;
}