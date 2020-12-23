/*................................
Name 			:- Ultrasonic Sensor
Author 		:- Abhishek Dongre
Date 			:- 28-030-20
..................................*/




#include<regx52.h>

#define SET						        1
#define RESET					        0
#define CMSETVALUE		        59

sbit TRIGGER = P2^6;				  //Output Setting bits
//sbit ECHO		 = P3^3;				//Input Setting bits


void HW_Init(void);
void UltraTRIGGER_10us(void);
unsigned int Ultra_ECHO(void);

