/*................................
Name 			:- Ultrasonic Sensor
Author 		:- Abhishek Dongre
Date 			:- 31-30-20
TIME			:- 01:10
..................................*/

#include <regx52.h>
#include "io.h"
#include "lcd.h"

void delay(unsigned int msec)
{
  int l,k;
  for(l=0;l<msec;l++)
  for(k=0;k<1275;k++);
}

void main(void)
{	
/*-------------------------------------------------INITIALIZATION ---------------------------------------------------------*/
		HW_Init();
/*-------------------------------------------------MAIN CODE----------------------------------------------------------------*/
	  while(1)
		{
			//GET_RANGE OF ULTRASONIC MODULE
				Ultra_ECHO();
			  delay(3);
		}
}

