#include <regx52.h>

#define LCD_PORT P0
   
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;
sbit BUSY = LCD_PORT^7;



void Busy_check(void);
void LCD_out(unsigned char,unsigned char);

  