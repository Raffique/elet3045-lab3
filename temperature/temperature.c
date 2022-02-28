#include "temperature.h"

void init_temperature(){										
	DDRA &= (~(1 << Adc_pin));	        /* Make ADC port as input */
	ADCSRA = 0x87;          /* Enable ADC, with freq/128  */
	ADMUX = 0x40;           /* Vref: Avcc, ADC channel: 0 */
}

float temperature()							
{
	float celsius;

	ADMUX = 0x40 | (0 & 0x07);   /* set input channel to read */
	ADCSRA |= (1<<ADSC);               /* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));     /* Wait until end of conversion by polling ADC interrupt flag */
	ADCSRA |= (1<<ADIF);               /* Clear interrupt flag */
	_delay_ms(1);                      /* Wait a little bit */
	celsius = (ADCW*4.88);
	celsius = (celsius/10.00);

	return celsius;
}
