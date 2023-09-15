/*
 * AMIT_Final_Gradution Project : Glove For Deaf
 *
 * Created: 02/08/2023 06:45:49 PM
 * Author : ziad
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <stdio.h>
#include <util/delay.h>


// macros
#define setbit(reg,bit) reg|=(1<<bit)		// set bit 1
#define clearbit(reg,bit) reg&=~(1<<bit)	// clear bit 0
#define toggelbit(reg,bit) reg^=(1<<bit)	// toggle
#define readbit(reg,bit) ((reg>>bit)&1)		// input read


#include "LCD.h"
#include "flex.h"
#include "ADC.h"



int main(void)
{
	
	
	// This is the Initialization  for the ADC Readings , LCD and the Flexible Sensor :
	
	flex_INIT();
	LCD_INIT();
    ADC_init();
	

    while (1) 
   {
	    // Use LCD in 2 line in 8-bit Mode:
		LCD_send_command(0x38);
		
		
		// Declaration for 5 Variable for The ADC Value  Reading for each Sensor:
		int Thumb_Finger   = ADC_Read(0);
		int Index_Finger   = ADC_Read(1);
		int Middle_Finger  = ADC_Read(2);
		int Ring_Finger    = ADC_Read(3);
		int Little_Finger  = ADC_Read(4);
		
		// Conversion of Flex Sensor ADC Value into ASCI Value , To be able to Compare it and Display the result on LCD
		itoa(Thumb_Finger,Thumb_String,10);
		itoa(Index_Finger,Index_String,10);
		itoa(Middle_Finger,Middle_String,10);
		itoa(Ring_Finger,Ring_String,10);
		itoa(Little_Finger,Little_String,10);

		//Compare Each Flex Sensor Result with the value of zero, in order to determine the Bend Degree for each Sensor:
		int Thumb_String_value = strcmp(Thumb_String, "0");
		int Index_String_value = strcmp(Index_String, "0");
		int Middle_String_value = strcmp(Middle_String, "0");
		int Ring_String_value = strcmp(Ring_String, "0");
		int Little_String_value = strcmp(Little_String, "0");

		
		// Analog Reading For the Flexible Sensor and Display Result of the Sign Language on the LCD :
	

		if (Thumb_String_value != 0  && Little_String_value ==0  && Index_String_value ==0  && Middle_String_value !=0   && Ring_String_value !=0 )
		{
			LCD_send_string(" That's Amazing ");
			LCD_send_string(" ");
			
		}
		
		
		else if (Thumb_String_value == 0  && Little_String_value ==0  && Index_String_value ==0  && Middle_String_value !=0   && Ring_String_value !=0)
		{
			LCD_send_string(" I Love You");
			LCD_send_string(" ");
			
			
		}
		
		else if (Thumb_String_value == 0  && Little_String_value == 0  && Index_String_value !=0  && Middle_String_value !=0   && Ring_String_value > 0)
		{
			LCD_send_string("Really!ILove You");
			LCD_send_string(" ");
			
		}
		
		else if (Thumb_String_value > 0  && Little_String_value > 0  && Index_String_value ==0  && Middle_String_value > 0   && Ring_String_value > 0)
		{
			LCD_send_string("Hey! You");
			LCD_send_string(" ");
		}
		
		else if (Thumb_String_value ==0  && Little_String_value > 0  && Index_String_value >0  && Middle_String_value > 0   && Ring_String_value > 0)
		{
			LCD_send_string("Good Job");
			LCD_send_string(" ");
			
			
		}
		
		else if (Thumb_String_value !=0  && Little_String_value > 0  && Index_String_value !=0  && Middle_String_value !=0   && Ring_String_value > 0)
		{
			LCD_send_string("I'm Watching You.");
			LCD_send_string(" ");
			
		}
		
		
		else
		{
			LCD_send_string(" NO READING ");
			LCD_send_string(" ");
			
		}
		
			 
    }
	return 0;
}



