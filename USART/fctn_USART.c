#include <mega16.h>
#include <stdlib.h>
#include <stdio.h>
#include <delay.h>
#include <math.h>
#include "fctn_USART.h"

//-- Atmega16 --
//-- Fontions pour utiliser l'USART --

//-- Constantes de configurations
#define FCLK 1000000                    //-- [Hz]
#define BAUD 2400
#define UBRR ((long) FCLK/(16*BAUD)-1)
#define char_size 8                     //-- 5-6-7-8 ou 9 bits
#define rx_en 1                         //-- 0 ou 1
#define tx_en 1                         //-- 0 ou 1
#define rx_it 1                         //-- 0 ou 1
#define tx_it 0                         //-- 0 ou 1
#define udr_it 0                        //-- 0 ou 1
#define parity 1                        //-- 0 : disabled / 1 = even / 2 : odd
#define mode_sel 'a'                    //-- 'a' : Asynch / 's' : synch
#define stop_bits 1                     //-- 1 ou 2
#define polarity 0                      //-- 0 ou 1
#define double_speed 0                  //-- 0 ou 1
#define multi_com 0                     //-- 0 ou 1

void init_USART() {

     char UCSRC_tempo = 0x80;    
     UBRRH = UBRR >> 8;            // Configuration du Baudrate
     UBRRL = UBRR & 0xFF;                         
     //-- Config size trame
     switch(char_size) {
          case 5:   UCSRB = (UCSRB & 0xFB);            // UCSZ2 = 0
                    UCSRC_tempo = (UCSRC_tempo & 0xF9);            //UCZS10 = 00
                    break;
          case 6:   UCSRB = (UCSRB & 0xFB);            // UCSZ2 = 0
                    UCSRC_tempo = (UCSRC_tempo & 0xF9) | 0x02;     // UCSZ10 = 01
                    break;
          case 7:   UCSRB &= 0xFB;                     // UCSZ2 = 0
                    UCSRC_tempo = (UCSRC_tempo & 0xF9) | 0x04;     // UCSZ10 = 10
                    break;   
          case 8:   UCSRB &= 0xFB;                     // UCSZ2 = 0
                    UCSRC_tempo = (UCSRC_tempo & 0xF9) | 0x06;     // UCSZ10 = 11
                    break;
          default:  UCSRB &= 0xFB;                     // UCSZ2 = 0     
                    UCSRC_tempo = (UCSRC_tempo & 0xF9) | 0x06;     // UCSZ10 = 11
                    break;
     }     
     //-- Config Polarity      
     if(polarity == 0) UCSRC_tempo &= 0xFE;
     else if(polarity == 1) UCSRC_tempo = (UCSRC_tempo & 0xFE) | 0x01;
     else;
     //-- Config Stop Bits
     if(stop_bits == 1) UCSRC_tempo &= 0xF7;
     else if(stop_bits == 2) UCSRC_tempo = (UCSRC_tempo & 0xF7) | 0x08;
     else;
     //-- Config mode
     if(mode_sel == 'a') UCSRC_tempo &= 0xBF;
     else if(mode_sel == 's') UCSRC_tempo = (UCSRC_tempo & 0xBF) | 0x40;
     //-- Config parity     
     if(parity == 0) UCSRC_tempo &= 0xCF;                                       //UPM10 = 00
     else if(parity == 1) UCSRC_tempo = (UCSRC_tempo & 0xCF) | 0x20;            // UMP10 = 10
     else if(parity == 2) UCSRC_tempo = (UCSRC_tempo & 0xCF) | 0x30;            // UPM10 = 11 
     else;
     //-- Config double speed (modif expression de UBRR si = 1, /8 et non /16)
     if(double_speed == 0) UCSRA &= 0xFD;
     else if(double_speed ==1) UCSRA = (UCSRA & 0xFD) | 0x02; 
     else;
     //-- Config multi com
     if(multi_com == 0) UCSRA &= 0xFE;
     else if(multi_com == 1) UCSRA = (UCSRA & 0xFE) | 0x01;          
     //-- Config it rx      
     if(rx_it == 0) UCSRB &= 0x7F;
     else if (rx_it == 1) UCSRB = (UCSRB & 0x7F) | 0x80;
     else;
     //-- Config it tx
     if(tx_it == 0) UCSRB &= 0xBF;
     else if (tx_it == 1) UCSRB = (UCSRB & 0xBF) | 0x40;
     else;
     //-- Config buffer empty config     
     if(udr_it == 0) UCSRB &= 0xDF;
     else if (udr_it == 1) UCSRB = (UCSRB & 0xDF) | 0x20;
     else;   
     //-- Config enable rx
     if(rx_en == 0) UCSRB &= 0xEF;
     else if(rx_en == 1) UCSRB = (UCSRB & 0xEF) | 0x10;
     else;
     //-- Config enable tx
     if(tx_en == 0) UCSRB &= 0xF7;
     else if(tx_en == 1) UCSRB = (UCSRB & 0xF7) | 0x08;
     else;
     //-- Ecriture de UCSRC en dernier pour eviter le conflit entre UBRRH-USCRC     
     UCSRC = UCSRC_tempo;           
}      


void envoi_USART(unsigned char data) {           
     while ( !( UCSRA & ( 1<< UDRE)) );
     UDR = data;                             // Envoie de la data par ecriture de UDR  // A completer pour envoie de 9 datas
}

char recep_USART() {
     while( !(UCSRA & (1 << RXC)) );         // Attente que le buffer soit rempli d'une data non lu
     return UDR;
}

void buffer_flush(void){                     // Permet de vider le buffer de reception (RXC => 0)
     unsigned char dummy;
     while ( UCSRA & (1 << RXC) ) dummy = UDR;
}