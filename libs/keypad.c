#include "keypad.h"

void keyinit()
{
    TRISB = 0XF0;
    OPTION_REG &= 0X7F; //ENABLE PULL UP
}
unsigned char key()
{
    PORTB = 0X00;
    while (C1 && C2 && C3 && C4)
        ;
    while (!C1 || !C2 || !C3 || !C4)
    {
        R1 = 0;
        R2 = R3 = R4 = 1;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 0;
            break;
        }
        R2 = 0;
        R1 = 1;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 1;
            break;
        }
        R3 = 0;
        R2 = 1;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 2;
            break;
        }
        R4 = 0;
        R3 = 1;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 3;
            break;
        }
    }
    if (C1 == 0 && C2 != 0 && C3 != 0 && C4 != 0)
        colloc = 0;
    else if (C1 != 0 && C2 == 0 && C3 != 0 && C4 != 0)
        colloc = 1;
    else if (C1 != 0 && C2 != 0 && C3 == 0 && C4 != 0)
        colloc = 2;
    else if (C1 != 0 && C2 != 0 && C3 != 0 && C4 == 0)
        colloc = 3;
    while (C1 == 0 || C2 == 0 || C3 == 0 || C4 == 0)
        ;
    return (keypad[rowloc][colloc]);
}