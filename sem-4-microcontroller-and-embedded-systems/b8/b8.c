//8. Display the Hex digits 0 to F on a 7-segment LED interface, with an
//appropriate delay in between.
#include <lpc214x.h>
#include <mc.h>
#define S 1 << 9
#define A 1 << 8
#define B 1 << 7
#define C 1 << 6
#define D 1 << 5
#define E 1 << 4
#define F 1 << 3
#define G 1 << 2
#define SEG(d) (S | (d << 2))

int digit[]=
	{

		/* 1=off 0=on */
		/* 8 7 6 5 4 3 2 ports */
		/* a b c d e f g DIGIT */
		SEG(0x01), /* 0b0 0 0 0 0 0 1 0 */
		SEG(0x4f), /* 0b1 0 0 1 1 1 1 1 */
		SEG(0x12), /* 0b0 0 1 0 0 1 0 2 */
		SEG(0x06), /* 0b0 0 0 0 1 1 0 3 */
		SEG(0x4c), /* 0b1 0 0 1 1 0 0 4 */
		SEG(0x24), /* 0b0 1 0 0 1 0 0 5 */
		SEG(0x20), /* 0b0 1 0 0 0 0 0 6 */
		SEG(0x0f), /* 0b0 0 0 1 1 1 1 7 */
		SEG(0x00), /* 0b0 0 0 0 0 0 0 8 */
		SEG(0x04), /* 0b0 0 0 0 1 0 0 9 */
		SEG(0x08), /* 0b0 0 0 1 0 0 0 A */
		SEG(0x60), /* 0b1 1 0 0 0 0 0 b */
		SEG(0x31), /* 0b0 1 1 0 0 0 1 C */
		SEG(0x42), /* 0b1 0 0 0 0 1 0 D */
		SEG(0x30), /* 0b0 1 1 0 0 0 0 E */
		SEG(0x38), /* 0b0 1 1 1 0 0 0 F */
	};
	
int main()
	{
		IO0DIR = S | A | B | C | D | E | F | G;
		//title does not work
		while(1)
		{
			int i;
			for(i=0; i < 16; i++)
			{
				IO0PIN = digit[i];
				delay(1000);
			}
		}
	}
