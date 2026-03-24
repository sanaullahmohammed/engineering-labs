//1. Display "Hello World" message using Internal UART.
#include <LPC214X.h>
#include <mc.h>
#define TX 01 << 0
#define WL 11 //(WL is 8, No parity, 1 Stop bit)
#define DLAB 1<<7
#define THRE 1 << 5

void init()
	{
		PINSEL0 = TX;
		U0LCR = DLAB;
		U0DLM = 0x00;
		U0DLL = 15000000 / (16*9600);
		U0LCR = WL; // Clear DLAB
	}
	
void tx(char ch)
{
		while(!(U0LSR & THRE));
		U0THR = ch; // Transmit the char
}

int main()
{
	int i;
	char msg[] = "Hello World\r\n";
	lcdln("UART");
	init();
	for (i=0; msg[i]; i++)
	{
			tx(msg[i]);
	}
}
