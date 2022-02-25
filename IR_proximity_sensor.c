#define F_CPU 1000000UL
 
#include <avr/io.h>
 
int ch_prime(int); //Prototyping the function for testing a number to be prime or not
 
int main(void)
{
          uint8_t num=0, res; //Creating variables 'num' & 'res' for storing the number of detections & result of the function respectively
          DDRA &= ~(1<<0); //Setting 0th pin of Port A as input
          DDRD |= (1<<0); //Setting 0th pin of Port D as output
 
          while(1)
          {
                   if (bit_is_set(PINA, 0)) //Checking if the sensor has detected something in front of it
                   {
                            while (bit_is_set(PINA, 0)); // We use the 'While' function to make sure that one detection increments the value of num by only one value
                            res = ch_prime(++num); //Incrementing the value of num and sending it to the function which tests it for being a prime number
 
                            if (res==1)
                            PORTD |= (1<<PIND0); //If returned value is 1, indicate prime number by pulling the 0th pin on Port D High
                            else
                            PORTD &= ~(1<<PIND0); //If returned value is 0, indicate composite number by pulling the 0th pin on Port D Low
                   }
                   else
                   continue; //If sensor has nothing in front of it, continue detecting
          }
}
 
int ch_prime(int num)
{
          int i; //Declaring variable 'i' to use in the for loop
          for (i=2;i<num;i++) //Run the loop for the value of i from '2' to 'num-1'
          {
                   if (num%i==0) //Check and compare to 0 the remainder when dividing num by i, if 0, then composite number
                   return(0); //If Number is composite, return 0
          }
          if (i==num) //Compare the value of i to num, if same, then prime number
          return(1); //If number is prime, return 1
}
