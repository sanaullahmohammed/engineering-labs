//7. Demonstrate the use of an external interrupt to toggle an LED On/Off.
#include <LPC214x.h>
#include <mc.h>
#define EINT2 0x02 << 30
#define LED 1 << 16
#define MODE 0x04 // Edge sensitive
#define POLARITY 0 // falling edge sensitive
#define IRQ 16
#define ENVEC 1 << 5
#define DI 0x04
void togleLed(int n)
	{
		int i;
		for (i=0; i < n; i++)
		{
			IO1SET = 0x00010000; // Turn ON
			delay(100);
			IO1CLR = 0x00010000; // Turn OFF
			delay(100);
		}
	}
void initLed()
	{
		IO1DIR = 1 << 16; // Select P1.16
		delay(10);
		IO1CLR = 1 << 16; // Clr P1.16
	}
void isr() __irq
	{
		togleLed(10);
		EXTINT |= DI; // Clear interrupt flag by writing 0b100 i.e EINT2
		VICVectAddr=0; // Finished ISR, dummy write
	}
void initIsr()
	{	
		PINSEL0 = EINT2; //0x80000000; warnings 16 << 30
		EXTMODE = MODE; // Edge sensitive mode on EINT2
		EXTPOLAR = 0; // Falling edge sensitive
		VICIntSelect = 0 << IRQ; // default is 0 anyway
		VICVectAddr0 = (unsigned long)isr; //Address of isr()
		VICVectCntl0 = ENVEC | IRQ; //Assign INTVEC to slot0 and enable it
		VICIntEnable = 1 << IRQ; // Enable ENT2 IRQ
	}
int main()
	{
		initIsr();
		initLed();
		lcdln("EINT...");
		while(1)
		{
		}
	}