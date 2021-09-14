#ifndef _LCD_H
#define _LCD_H
#include <xc.h>
#include "config.h"
#define LCD_EN_Delay 500
#define LCD_DATA_PORT_D TRISD
#define LCD_EN_Delay 500
#define LCD_DATA_PORT_D TRISC
#define LCD_RS_D TRISC5
#define LCD_EN_D TRISC4
#define RS RC5
#define EN RC4
#define D4 RC6
#define D5 RC1
#define D6 RC2
#define D7 RC3
void LCD_Init();
void LCD_Clear();
void LCD_SL();
void LCD_SR();
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_Set_Cursor(unsigned char, unsigned char);
void LCD_Write_Char(char);
void LCD_Write_String(char*);
#endif