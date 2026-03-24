#include<LPC214X.h>
#define TX (0x1 << 0)
#define DLAB (1 << 7)
#define WL (0x3 << 0)
#define THRE (1 << 5)

void init()
{
	PINSEL0 = TX;
	U0LCR = DLAB;
	U0DLM = 0x00;
	U0DLL = 15000000/(16*9600);
	U0LCR = WL;
}

void tx(char ch)
{
	while(!(U0LSR & THRE));
	
	U0THR = ch;
}

int main()
{
	int i;
	char msg[] = "Hello World\r\n";
	init();
	for(i=0;msg[i];i++)
	{
		tx(msg[i]);
	}
}
