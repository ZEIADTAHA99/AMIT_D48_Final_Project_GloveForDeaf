/*
 * LCD.c
 *
 * Created: 02/08/2023 06:50:46 PM
 *  Author: ziad
 */ 


#include <avr/io.h>  // DDRA PIN PORT
#include <util/delay.h>


// macros
#define setbit(reg,bit) reg|=(1<<bit)		// set bit 1
#define clearbit(reg,bit) reg&=~(1<<bit)	// clear bit 0
#define toggelbit(reg,bit) reg^=(1<<bit)	// toggle
#define readbit(reg,bit) ((reg>>bit)&1)		// input read

#include "LCD.h"

void LCD_send_command(unsigned char cmd)
{
	LCD_Data_Port = cmd;   //command
	// mesh active till enable opend
	
	clearbit(LCD_Control_Port,RS);  // rs = 0
	clearbit(LCD_Control_Port,RW);  // rw = 0  write
	setbit(LCD_Control_Port,EN);    // EN = 1
	_delay_us(1);					// micro second
	clearbit(LCD_Control_Port,EN);  // EN = 0
	_delay_ms(3);                   //milli  lcd command <+> command
}

void LCD_send_data(unsigned char data)
{
	LCD_Data_Port = data ;  // port == data
	
	setbit(LCD_Control_Port,RS);    // RS = 1 --> lcd command--> 0 data-->1
	clearbit(LCD_Control_Port,RW);	// write ==> 0
	setbit(LCD_Control_Port,EN);	//EN = 1
	_delay_us(1);					// delay 1 us
	clearbit(LCD_Control_Port,EN);  // en =0
	_delay_ms(1);					// lcd to separate from two data sending operations
}
void LCD_INIT(void)
{
	LCD_Data_Dir =0xff;		//all output DDRC = 255 or 0xff
	
	setbit(LCD_Control_Dir,EN);  // EN pin output
	setbit(LCD_Control_Dir,RS);	 // RS pin out
	setbit(LCD_Control_Dir,RW);	 // RW output
	_delay_ms(20);				// to make sure power is on for lcd 4.5v
	// > 15 ms
	LCD_send_command(0x38);		// LCD in 8 bit mode and 2 lines  5*8 dots
	LCD_send_command(0x0C);		// LCD DISPLY ON CURSER OFF
	LCD_send_command(0x06);		// LCD AUTO INCRMENT
	LCD_send_command(0X01);		// LCD CLEAR SCREAN 00000001
	// make sure there is nothing on lcd
	
	LCD_send_command(0X80);		// HOME POSITION
	
}

void LCD_send_string( char str[])
{
	//          01234567\0
	//char * p = "asdfghjk";
	
	int count =0;
	
	while(str[count]!=0)
	{
		LCD_send_data(str[count]);
		count++;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


