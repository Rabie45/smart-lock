#ifndef _KEYPAD_H
#define _KEYPAD_H
#include <xc.h>
#include "config.h"
#define R1 RB0
#define R2 RB1
#define R3 RB2
#define R4 RB3
#define C1 RB4
#define C2 RB5
#define C3 RB6
#define C4 RB7
#define Keypad_PORT PORTB
#define Keypad_PORT_Direction TRISB
unsigned char key();
void keyinit();
unsigned char keypad[4][4] = {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'C', '0', '=', '+'}};
unsigned char rowloc, colloc;
#endif