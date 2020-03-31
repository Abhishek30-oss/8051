/*................................
Name 			:- Ultrasonic Sensor
Author 		:- Abhishek Dongre
Date 			:- 28-030-20
Time			:- 20:54
.......................*/


#include "lcd.h"

/*---------------------------------BUSY CHECK LOGIC--------------------------------------------------------------------------*/
void Busy_check(void)
  {
			RS=0;
			RW=1;
			BUSY=1;
			do
			{
         EN=0;
         EN=1;
			}while(BUSY==1);
	}
	
/*---------------------------------LCD DISPLAY LOGIC--------------------------------------------------------------------------*/	
void LCD_out(unsigned char x,unsigned char y)
	{
			RW=0;
			if(x==0)
          RS=0;
			else 
          RS=1;
			LCD_PORT=y;
			EN=1;
			EN=0;
	}