#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

void Triggger()
{
	pinMode(wPi_Pin, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS);
	softPwmCreate(wPi_Pin, drh, period)
	//softPwmWrite(wPi_Pin, 70);
	
	delay(5000);
	softPwmStop(wPi_pin);
