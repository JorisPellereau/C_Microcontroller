#include <mega16.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>
#include "mpp.h"

// Commande de moteur pas à pas Unipolaire
// Commande sur les 4 bits de poids faible d'1 port
//     PORTA : XXXX DCBA
void mpp_exc1(char sens) {              

     if(sens == 1) {
          PORTA = (PORTA & 0xF0) | 0x03;       // AB = 1
          delay_ms(100);
          PORTA = (PORTA & 0xF0) | 0x06;       // BC = 1
          delay_ms(100);
          PORTA = (PORTA & 0xF0) | 0x0C;       // CD = 1
          delay_ms(100);
          PORTA = (PORTA & 0xF0) | 0x09;       // DA = 1
          delay_ms(100);
     }
     else if(sens == 2) {
          PORTA = (PORTA & 0xF0) | 0x09;       // DA = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x0C;       // CD = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x06;       // BC = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x03;       // AB = 1
          delay_ms(1);
     }
     else;

}

void mpp_exc2(char sens) {

     if(sens == 1) {
          PORTA = (PORTA & 0xF0) | 0x01;       // A = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x03;       // AB = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x02;       // B = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x06;       // BC = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x04;       // C = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x0B;       // CD = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x08;       // D = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x09;       // DA = 1
          delay_ms(1);         
     }
     else if(sens == 2) {
          PORTA = (PORTA & 0xF0) | 0x09;       // DA = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x08;       // D = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x0B;       // CD = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x04;       // C = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x06;       // BC = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x02;       // B = 1
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x03;       // AB = 1 
          delay_ms(1);
          PORTA = (PORTA & 0xF0) | 0x01;       // A = 1
          delay_ms(1);
     }
     else;

}