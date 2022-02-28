#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#define  Trigger_pin	PA0	/* Trigger pin */
#define  Echo_pin       PD5

int TimerOverflow = 0;

char string[10];
long count;
double distance;
	
void init_ultrasonic();
double ultrasonic();