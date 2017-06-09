#include <mega16.h>

//-- Fonction pour un KeyPad 16 touches
/*
     1 - 2 - 3 - A = ROW1
     |   |   |   |
     4 - 5 - 6 - B = ROW2
     |   |   |   |
     7 - 8 - 9 - C = ROW3
     |   |   |   |
     * - 0 - # - D = ROW4
     |   |   |   |
    Cl1 Cl2 Cl3 Cl4

        Col1 Col2 Col3 Col4 Row1 Row2 Row3 Row4
PINs     1    2    3    4    5    6    7    8
PORTA :  7    6    5    4    3    2    1    0
 I/O     I    I    I    I    O    O    O    O


*/


void init_keypad(void) {
     DDRA = 0x0F;
     PORTA = 0x00;
}

unsigned char lecture_keypad() {
     unsigned char key = 'Y' , init_port, i ,read_port;
     init_port = 0x10;
     PORTA = init_port;
     i = 0;
     while(i < 4) {
          PORTA = PORTA >> 1; 
          read_port = PINA;       // Lecture du PORTA
          i++;
          switch(read_port) {
               case 0x88:     key = '1';
                              i = 4;    // Pour sortir de la boucle car une touche a �t� d�tect�e
                              break;
               case 0x48:     key = '2';
                              i = 4;
                              break;
               case 0x28:     key = '3';
                              i = 4;
                              break;
               case 0x18:     key = 'A';
                              i = 4;
                              break;
               case 0x84:     key = '4';
                              i = 4;
                              break;
               case 0x44:     key = '5';
                              i = 4;
                              break;
               case 0x24:     key = '6';
                              i = 4;
                              break;
               case 0x14:     key = 'B';
                              i = 4;
                              break;
               case 0x82:     key = '7';
                              i = 4;
                              break;
               case 0x42:     key = '8';
                              i = 4;
                              break;
               case 0x22:     key = '9';
                              i = 4;
                              break;
               case 0x12:     key = 'C';
                              i = 4;
                              break;
               case 0x81:     key = '*';
                              i = 4;
                              break;
               case 0x41:     key = '0';
                              i = 4;
                              break;
               case 0x21:     key = '#';
                              i = 4;
                              break;
               case 0x11:     key = 'D';
                              i = 4;
                              break;
               default:       key = 'X';
                              break;                               
          }
     
     }
     while((PINA & 0xF0 == 0x80) || (PINA & 0xF0 == 0x40) || (PINA & 0xF0 == 0x20) || (PINA & 0xF0 == 0x10) );     // Attente relachement de la touche
     PORTA = 0x00;
     return key;
}