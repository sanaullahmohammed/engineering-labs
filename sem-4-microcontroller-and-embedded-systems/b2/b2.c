//2. Interface and Control a DC Motor.
#include <lpc214x.h>
#include <mc.h>
// if old kit, single port 25
#define IN1 (1 << 30)
#define IN2 (1 << 31)
#define PMW (1 << 21)
void delay(int n);
void motor(int IN)
	{
		IO1PIN = IN;
		delay(1000); // allow to run for 5s
	}
int main()
{
	IO1DIR = IN1 | IN2;
	IO0DIR = PMW;
	IO0SET = PMW;
	lcdln("DC MOTOR");
	while (1)
	{
		motor(IN1);
		motor(IN2);
	}
}