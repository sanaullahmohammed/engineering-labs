//6. Interface a 4x4 keyboard and display the key code on an LCD.
#include <lpc21xx.h>
#include <mc.h>
#define COL1 1 << 16
#define COL2 1 << 17
#define COL3 1 << 18
#define COL4 1 << 19
#define ROW1 1 << 20
#define ROW2 1 << 21
#define ROW3 1 << 22
#define ROW4 1 << 23
char keypad[] = // keypad[20:23, 16:19]
{
'0', '4', '8', 'C',
'1', '5', '9', 'D',
'2', '6', 'A', 'E',
'3', '7', 'B', 'F'
};
/* Rows are connected to input ports. They are at HIGH (by default)
** Cols are connected to output ports. They will be set to HIGH.
** Scan to find Row X that has become LOW due to driving Col Y as LOW
**/
char keypadscan(void) //Keypad Scan
{
	int col, row, key;
	IOSET1 = COL1 | COL2 | COL3 | COL4; //Set the cols to HIGH
	key = 0;
	for (col=16; col <= 19; col++)
	{
		IOCLR1 = (1 << col); //Set this col to LOW while other cols at '1'
			for (row=20; row <= 23; row++)
			{
				if(!(IOPIN1 & (1 << row))) //Scan for key press, row is col LOW
					{
						return keypad[key];
					}
				key++;
			}
			IOSET1 = (1 << col); //Set this col to HIGH again, before trying next column
	}
	return('X');
}

void initKeypad()
{
		IO1DIR = COL1 | COL2 | COL3 | COL4; // Output columns
}

int main(void)
{
	char c;
	char s[10];
	initKeypad();
	lcdln("KEPAD...");
	while(1)
	{
		c = keypadscan(); //Obtaining values from keypad
		if (c == 'X') continue;
		sprintf(s, "%c", c);
		lcdln(s);
	}
}
