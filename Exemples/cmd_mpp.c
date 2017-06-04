/*****************************************************
Project : Commande d'un MPP via une communication USART
Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 1,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <stdlib.h>
#include <delay.h>
#include <stdio.h>
#include <math.h>
#include "fctn_USART.h"
#include "mpp.h"

//-- GLOBAL VARIABLE --
unsigned char mod;

// -- Constante --
#define baudr 2400
#define foscl 1000000

void main(void) {
      
     // Global interrupt
     SREG = SREG | 0x80;      // Init All IT
     
     //-- Config des PORTS --
     PORTA=0x00;
     DDRA=0xFF;               // Sorties
     PORTB=0x00;
     DDRB=0x00; 
     PORTC=0x00;
     DDRC=0xFF;
     PORTD=0x00;
     DDRD=0x00;

     //-- Timer/Counter 0 initialization --
     TCCR0=0x00;
     TCNT0=0x00;
     OCR0=0x00;
     
     //-- Timer/Counter 1 initialization --
     TCCR1A=0x00;
     TCCR1B=0x00;
     TCNT1H=0x00;
     TCNT1L=0x00;
     ICR1H=0x00;
     ICR1L=0x00;
     OCR1AH=0x00;
     OCR1AL=0x00;
     OCR1BH=0x00;
     OCR1BL=0x00;

     //-- Timer/Counter 2 initialization --     
     ASSR=0x00;
     TCCR2=0x00;
     TCNT2=0x00;
     OCR2=0x00;
     
     //-- External Interrupt(s) initialization // INT0: Off // INT1: Off  // INT2: Off
     MCUCR=0x00;
     MCUCSR=0x00;

     //-- Timer(s)/Counter(s) Interrupt(s) initialization
     TIMSK=0x00;

     //-- USART initialization --
     init_USART(baudr , foscl);

     //-- Analog Comparator initialization --
     ACSR=0x80;
     SFIOR=0x00;

     //-- ADC initialization    // ADC disabled
     ADCSRA=0x00;

     //-- SPI initialization // SPI disabled
     SPCR=0x00;

     // TWI initialization // TWI disabled
     TWCR=0x00;

     while (1) {                                          
          if(mod == 0) mpp_exc1(PORTA , 1);
          else if (mod ==1) mpp_exc1(PORTA , 2);
          else;                               
     }
}

     interrupt[USART_RXC] void RX_complete(void) {
          unsigned char * ptr;
          ptr = &mod;
          *ptr = UDR;
          buffer_flush();          // Use for RAZ RXC bit sinon Toujours en IT !!!!
     }
