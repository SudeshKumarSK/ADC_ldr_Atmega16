#include<avr/io.h>
#include<util/delay.h>

void init_adc()                             // ADC intialising function

{

ADCSRA= ADCSRA | (0b00000001<<ADEN);       // Enable the ADC
ADCSRA= ADCSRA | (0b00000001<<ADPS2);      // set the sampling rate
ADMUX= ADMUX |   (0b00000001<<REFS0);      // set the reference voltage     

}

unsigned int read_adc()

{
int p=0b00000011;              // select the input pin

ADMUX = ADMUX | p;              // ADMUX

ADCSRA = ADCSRA | (0b00000001<<ADSC);    // start converson

while((ADCSRA & (0b00000001<<ADIF))==0);  // check for end conversion

ADCSRA= ADCSRA | 0b00000001<<ADIF;         

return(ADC);               // get the output from ADC
}

void main()
{
DDRB=0b11111111;          // PARTB is output
init_adc();

_delay_ms(50);
unsigned int a;
unsigned int p;

unsigned int t;
unsigned int ton;
unsigned int toff;

while(1)
{
p= read_adc();
a= (p/40);
t= 25.6;
toff=a;

ton=t-toff;

if(p<742)

{

PORTB=0b00001010;
_delay_ms(ton);
PORTB=0b00000000;
_delay_ms(toff);
}

else

PORTB=0b00000000;
}

} 



