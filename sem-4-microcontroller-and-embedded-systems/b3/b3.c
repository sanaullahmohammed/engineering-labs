//3. Interface a Stepper motor and rotate it in clockwise and anti-clockwise direction.
#include <lpc214x.h>
#include <mc.h>
#define A (1 << 16)
#define B (1 << 17)
#define C (1 << 18)
#define D (1 << 19)
#define STEPS 60 //55 steps with 100 ms delay gives one complete rotation.
#define DELAY 100 //10 ms, increased delay cause slowdown in speed
void motor(int coil[])
	{
		int i, n;
		for (i=0; i < STEPS; i++)
		{
			for(n=0; n < 4; n++)
			{
				IOPIN0 = coil[n]; // Set the P0.n value HIGH
				delay(DELAY);
			}
		}
	}
	
int main()
{
	int coils_n[] = {A, B, C, D};
	int coils_r[] = {D, C, B, A};
	IO0DIR = A | B | C | D;
	//title does not work
	while(1)
	{
		motor(coils_n);
		motor(coils_r);
	}
}