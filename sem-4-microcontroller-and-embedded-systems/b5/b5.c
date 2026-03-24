//5. Interface a DAC and generate Triangular and Square waveforms.
#include <LPC214x.h>
#include <mc.h>
#define AOUT 0x2 << (2*(25-16))
#define BIAS 1 //setling time is 2.5 \mu{}S
#define DATA(d) ((d << 6) & 0x0001FFC0);
void triangle()
{
	int d;
	d = 0;
	while (d != 1023)
	{
		DACR = DATA(d);
		d++;
		//delay(1);
	}
	while (d != 0)
	{
		DACR = DATA(d)
		d--;
		//delay(1);
	}
}
void square()
{
	int d;
	// Square wave
	d = 1023;
	DACR = DATA(d);
	delay(1);
	d = 0;
	DACR = DATA(d);
	delay(1);
}
int main()
{
	int i;
	PINSEL1 = AOUT;

	while(1)
	{
		for (i=0; i <5; i++)
		triangle();
		for (i=0; i <5; i++)
		square();
	}
}
