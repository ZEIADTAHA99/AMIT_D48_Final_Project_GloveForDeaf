/*
 * flex.h
 *
 * Created: 03/09/2023 12:47:35 PM
 *  Author: ziad
 */ 


#ifndef FLEX_H_
#define FLEX_H_

// Declaration for 5 Variable for each Flexible  Sensor
int Thumb_Finger  ;
int Index_Finger  ;
int Middle_Finger ;
int Ring_Finger   ;
int Little_Finger ;

// Declaration for 5 Variable for The String ADC Value  Reading for each Sensor to be able to display and compare and display result on LCD:
char Thumb_String[5];
char Index_String[5];
char Middle_String[5];
char Ring_String[5];
char Little_String[5];


void flex_INIT(void);
int flex_reading_Thumb (void);
int flex_reading_Index(void);
int flex_reading_Middle(void);
int flex_reading_Ring(void);
int flex_reading_Little(void);


#endif /* FLEX_H_ */