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
         1    2    3    4    5    6    7    8
PORT :   7    6    5    4    3    2    1    0
 I/O     I    I    I    I    O    O    O    O


*/
void init_keypad(void);
unsigned char lecture_keypad();