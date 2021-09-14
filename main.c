#include <xc.h>
#include "libs/config.h"
#include "libs/keypad.h"
#include "libs/LCD.h"
char word[] = {'0', '1', '2', '3'};
unsigned char KEY, star = '*';

int main()
{
    TRISD0 = 0;
    RD0 = 0;
    TRISD1 = 0;
    RD1 = 0;

    LCD_Init();
    keyinit();
    
    int val=0;
    do
    {
        val = Auth();
    } while (val != 1);

    LCD_Clear();
    LCD_Set_Cursor(1, 1);
    LCD_Write_String("door opened");
    __delay_ms(1000);
    RD0 = 1;
    __delay_ms(1000);
    RD0 = 0;
    __delay_ms(1000);
    RD1 = 1;
    __delay_ms(1000);
    RD1 = 0;
    __delay_ms(1000);
    val = 0;

    while (1)
    {
        /* code */
    }
}
int Auth()
{
    LCD_Clear();
    LCD_Set_Cursor(1, 1);
    LCD_Write_String("enter the pass");
    int len = 0;
    len = sizeof(word) / sizeof(char);
    for (int i = 0; i <= len - 1; i++)
    {
        KEY = key();
        if (word[i] == KEY)
        {
            LCD_Set_Cursor(2, i + 1);
            LCD_Write_Char(star);
            if (i == len - 1)
                return 1;
        }
        else
        {
            LCD_Clear();
            LCD_Set_Cursor(1, 1);
            LCD_Write_String("error");
            __delay_ms(1000);
            break;
        }
    }
}