/*............................
Name 			:- Ultrasonic Sensor
Author 			:- Abhishek Dongre
Date 			:- 31-03-20
Time			:- 15:49
.......................*/



#include "io.h"
#include "lcd.h"

unsigned int DISTANCE = 0;
unsigned char i,Display[] = "Distance =";

/*------------------------------- HARDWARE INITIALIZATION -------------------------------------------------------------*/
void HW_Init(void)
{
	  //LCD INITIALIZATION
	  Busy_check();
	  LCD_out(0,0x38);
   	  Busy_check();
	  LCD_out(0,0x0E);
	  Busy_check();
	  LCD_out(0,0x01);
	  Busy_check();
	  LCD_out(0,0x80);
	
	  for(i=0;Display[i]!='\0';i++)
            {
                 Busy_check();
		 LCD_out(1,Display[i]);
	    }
						
		//HARDWARE  INITIALIZATION		
		TRIGGER = RESET;							//Configure as output	 
    		TMOD = 0x91;	
   		TR1 = 1;
    		TH1 = 0x00;	TL1 = 0x00;
   		P3 |= 0x04;								//Configure INT1 AS INPUT
						
}

/*--------------------------Sending 10 us HIGH PULSE -----------------------------------------------------------*/
 void UltraTRIGGER_10us(void)
{
	  TL1 = 0x00; 	TH1 = 0x00;					//TIMER 1
	  TL0	= 0xF6;	  TH0	= 0xFF;					//TIMER 0 10US
		TRIGGER = SET;
		TR0 = SET;
		while(!TF0);						//Wait till overflow flag is set
	  	TRIGGER = RESET;					//send low pulse
		TF0 = RESET;	TR0 = RESET;
	 
}


/*--------------------------------ECHO RECEIVED --------------------------------------------------------------------*/
unsigned int Ultra_ECHO(void)
{
	 unsigned int TIMER_VALUE = 0;
	 UltraTRIGGER_10us();
	 while(!INT1);							//WAIT TILL LOW PULSE
         while(INT1); 							//TIMER STARTS AND STOPS AFTER LOW PULSE
	
   TIMER_VALUE = ((TH1 << 8)| TL1);
	
	 if(TIMER_VALUE < 38000)
	 {
			DISTANCE = TIMER_VALUE / CMSETVALUE;		//CALCULATE DISTANCE IN CMS
		  
		 if(DISTANCE!=0)
			{
				Busy_check();
				LCD_out(0,0x8A);
				Busy_check();
				LCD_out(1,(( DISTANCE / 100 )+ 48 ));
				Busy_check();
				LCD_out(1,((( DISTANCE / 10) % 10) + 48 ));
				Busy_check();
				LCD_out(1,((DISTANCE % 10 ) + 48));
				Busy_check();
				LCD_out(1,' ');
				Busy_check();
				LCD_out(1,'C');
				Busy_check();
				LCD_out(1,'M');
			}
	 }
	 else
	 {
		 DISTANCE = 0;
		 Busy_check();
		 LCD_out(0,0x8B);
	         Busy_check();
		 LCD_out(1,(0+48));
	}
   return TIMER_VALUE;
}


