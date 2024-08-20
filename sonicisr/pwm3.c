#include <stdio.h>
#include <wiringPi.h>

#define wPi_pwm1 12

// Using hardware Pwm  
int main()
{
	wiringPiSetup();
	pinMode(wPi_pwm1, OUTPUT);
	
	while(1){
		for (int i = 0; i < 1024; i++)
		{
			pwmWrite(wPi_pwm1, i);
			delay(100);
		}
		for (int i = 1024; i>0; --i)
		{
			pwmWrite(wPi_pwm1, i);
			delay(100);
		}
	}
	return 0;
}
