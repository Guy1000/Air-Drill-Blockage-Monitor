
/*
 * SensorV0.1.cpp
 *
 * Created: 2023-10-19 4:44:04 PM
 * Author : Aron Derksen
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <avr/delay.h>

int main(void)
{
    PORTA.DIR |= PIN6_bm;
	int val = 0;
	float ref = 0;
	float rate = 0.01;
	ADC0_CTRLA = 0; //Configure resolution
	ADC0_CTRLC = 0b01010100;//Configure VREF
	ADC0_MUXPOS = 0x07;//MUX
	ADC0_CTRLA |= ADC_ENABLE_bm;
	ADC0_COMMAND = ADC_STCONV_bm;
	while(ADC0_COMMAND && ADC_STCONV_bm){
		
	}
	ref = (ADC0_RES) + 5;
    while (1) 
    {
		
		ADC0_COMMAND = ADC_STCONV_bm;
		while(ADC0_COMMAND && ADC_STCONV_bm){
			
		}
		val = (ADC0_RES);
		if(val >= ref){
			PORTA.OUT |= PIN6_bm;
		} else {
			PORTA.OUT &= ~PIN6_bm;
		}
		ref = ref + ((val - ref + 5)*rate);
		
    }
}