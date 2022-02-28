#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "lcd/lcd.h"
#include "voltage/voltage.h"
#include "temperature/temperature.h"
#include "ultrasonic/ultrasonic.h"

char mode = 0;

int main(void){

    LCD_Init();			/* Initialization of LCD*/
    init_volts();

    DDRD=0xe0;   //Configure INT0,INT1 as input and PORTD5-PORTD7(rs,rw,en) as output
    
    GICR=0xc0;   //Enable External Interrupts INT0 and INT1
	MCUCR=0x08;  //Configure INT0 active low level triggered and INT1 as falling edge
	
	sei();     // Enable global interrupts by setting global interrupt enable bit in SREG


    while(1){

        switch (mode)
        {
        case 0: /*DC Voltmeter*/
            /* code */
            LCD_Clear();
            LCD_String("Voltage");
            char val[7];
            while (mode == 0){
                dtostrf(voltage(), 5, 2, val);
                LCD_String_xy(1, 0, val);
                LCD_String("v");
            }
            break;

        case 1: /*Capacitance meter*/
            /* code */
            LCD_Clear();
            LCD_String("Capacitance");
            break;

        case 2: /*Resistace meter*/
            /* code */
            LCD_Clear();
            LCD_String("Resistance");
            break;

        case 3: /*Temperature meter*/
            /* code */
            init_temperature();
            LCD_Clear();
            LCD_String("Temperature");
            char val[7];
            while (mode == 3){
                dtostrf(temperature(), 5, 2, val);
                LCD_String_xy(1, 0, val);
                LCD_String(" *C");
            }
            break;

        case 4: /*Frequency meter*/
            /* code */
            LCD_Clear();
            LCD_String("Frequency");
            break;

        case 5: /*Distance Meter*/
            /* code */
            init_ultrasonic();
            LCD_Clear();
            LCD_String("Distance");
            char val[7];
            while (mode == 5){
                dtostrf(ultrasonic(), 5, 2, val);
                LCD_String_xy(1, 0, val);
                LCD_String("uF");
            }
            break;
        
        default:
            break;
        }

    }
}

ISR (INT0_vect)          //External interrupt_zero ISR
{
	if (mode > 5){
        mode = 0;
    }
    else{
        mode += 1;
    }
}