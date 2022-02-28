//This is for the LM35 temperature sensor

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

#define Adc_pin 0

void init_temperature();

float temperature();