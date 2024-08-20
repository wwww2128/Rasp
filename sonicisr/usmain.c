#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

extern void Trigger();
extern void usISR();
extern double dist;

int main()
{	
	wiringPiSetup();
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	wiringPiISR(ECHO, INT_EDGE_BOTH, usISR); //  Regist ISR
	
	while(1)
	{
		pwm
	}
}
