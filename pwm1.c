#include <stdio.h>
#include <wiringPi.h>

#define wPi_22 22

int main(int n, char * s[])
{
	if (n < 2)
	{
		printf("usage : pwm1 [duty_rate(%%)]\n\n");
		printf("		period = 10 ms if empty \n\n");
		return 1;
	}
	int dr, drh, drl, period = 10;
	sscanf(s[1], "%d", &dr);		// 70
	if(n>2) sscanf(s[2], "%d", &period);	// if Argument n>2 &period
	drh = (dr * period) / 100;		// 7
	drl = period - drh;				// 3
	wiringPiSetup();	// wPi pin numbering 
	
	pinMode(wPi_22, OUTPUT);
	for (int i = 0; i < 10; i++)
	{
		digitalWrite(wPi_22, 1);
		delay(drh);
		digitalWrite(wPi_22, 0);
		delay(drl);
	}
	return 0;
}
