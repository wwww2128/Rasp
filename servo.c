#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>

#define wpi_servo 1

void signal_handler(int signum) { // <signal.h>
    if (signum == SIGINT) { // Ctrl+C를 받았을 때 수행
        pwmWrite(wpi_servo, 0);
        pinMode(wpi_servo, INPUT);
        exit(signum); // <stdlib.h>
    }
}

int main(int argc, char **argv)
{
	signal(SIGINT, signal_handler);
	wiringPiSetup();
	pinMode(wpi_servo, OUTPUT);
	
	for (int j = 0; j < 50; j++)
	{
	for (int i = 0; i < 10; i++)
	{
	digitalWrite(wpi_servo, 1);
	delayMicroseconds(1000);
	digitalWrite(wpi_servo, 0);
	delayMicroseconds(19000);
	}
	for (int i = 0; i < 10; i++)
	{
	digitalWrite(wpi_servo, 1);
	delayMicroseconds(2000);
	digitalWrite(wpi_servo, 0);
	delayMicroseconds(19800);
	}
}
	return 0;
}

