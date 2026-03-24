//4. Determine Digital output for a given Analog input using Internal ADC of ARM controller.
#include <lpc214x.h>
#include <stdio.h>
#include <string.h>
#include <mc.h>
#define ADC3 01 << (2*(30-16))
#define SEL 1 << 3 // select 3rd channel
#define CLKDIV 3 << 8 // 3MHz
#define BURST 1 << 16 // Burst
#define PDN 1 << 21 // power down mode 1 is operations
#define START 0 << 24 // start conversion
#define DONE 1 << 31 // data is available
#define DATA(AD0DR3) ((AD0DR3 >> 6) & 0x3FF) // 10bit ADC data

void initAdc()
{
	PINSEL1 = ADC3;
	AD0CR = START | BURST |PDN | CLKDIV | SEL; //0x00210308
}
int readAdc()
{
	AD0CR |= START;
	while (!(AD0DR3 & DONE)); // Wait till conversion DONE
	return DATA(AD0DR3); // read 10bit data
}
int main(void)
{
	int rv;
	float voltage;
	char s[10];
	initAdc();
	lcdln("ADC...");
	while(1)
	{
		rv = readAdc();
		voltage = (rv/1023.0)*3.3; // Convert ADC value to equivalent voltage
		sprintf(s, "%.2f", voltage);
		lcdln(s);
		delay(1000);
	}
}
