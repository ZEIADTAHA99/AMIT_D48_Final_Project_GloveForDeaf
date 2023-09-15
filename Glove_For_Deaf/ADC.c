/*
 * ADC.c
 *
 * Created: 15/09/2023 04:15:17 PM
 *  Author: ziad
 */ 

#include <avr/io.h>  // DDRA PIN PORT
#include <util/delay.h>


// macros
#define setbit(reg,bit) reg|=(1<<bit)		// set bit 1
#define clearbit(reg,bit) reg&=~(1<<bit)	// clear bit 0
#define toggelbit(reg,bit) reg^=(1<<bit)	// toggle
#define readbit(reg,bit) ((reg>>bit)&1)		// input read

#include "ADC.h"


void ADC_init() // init
{

	ADMUX  |=(1<<REFS0);  //AVCC with external capacitor at AREF pin
	ADCSRA |=(1<<ADEN);   //ADC Enable
	ADCSRA |=(1<<ADPS2);  //PRESCALER 16 --> freq = 62500 Hz //ADC speed must be in range of 50k to 200k HZ
	ADCSRA |=(1<<ADSC);
	

}

int ADC_Read (char channel)
{
	int Ain,AinLow;
	
	ADMUX &=0xF0;       // Clear Older Channel That was Read
	ADMUX  |=channel;  // Define the new ADC Channel to be read
	
	ADCSRA |=(1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	_delay_us(10);
	
	AinLow = (int)ADCL;		   /* Read lower byte*/
	Ain = (int)ADCH*256;	   /* Read higher 2 bits and  Multiply with weight */
	Ain = Ain + AinLow;
	
	return(Ain);			    /* Return digital value*/
}


