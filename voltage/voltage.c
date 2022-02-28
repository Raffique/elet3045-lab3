/*
* C code for Digital Voltmeter using ATmega32 Microcontroller
 */ 

#include "voltage.h"

void init_volts(){

    DDRA = 0; //this is for the voltgae pin PA0/ADC0
    DMUX |=(1<<REFS0);
    ADCSRA |=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
    ADCSRA |=(1<<ADSC);
}

float voltage()
{
    
    return ADC/204.8*18;//ADC/18.618;
}
