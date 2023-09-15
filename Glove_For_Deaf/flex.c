/*
 * flex.c
 *
 * Created: 03/09/2023 12:50:02 PM
 *  Author: ziad
 */ 


#include <avr/io.h>  // DDRA PIN PORT
#include <util/delay.h>


// macros
#define setbit(reg,bit) reg|=(1<<bit)		// set bit 1
#define clearbit(reg,bit) reg&=~(1<<bit)	// clear bit 0
#define toggelbit(reg,bit) reg^=(1<<bit)	// toggle
#define readbit(reg,bit) ((reg>>bit)&1)		// input read

#include "flex.h"
#include "ADC.h"


// Initilization for Reading of ADC Values for each sensor and set the ADC Pins of ATMega32 into Input Pins :
void flex_INIT(void)
{
   clearbit(DDRA,0);//adc0 input
   clearbit(DDRA,1);//adc1 input
   clearbit(DDRA,2);//adc2 input
   clearbit(DDRA,3);//adc3 input
   clearbit(DDRA,4);//adc4 input
}
