#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

double Dist()
{
	//Trigger Siganl 
	digitalWrite(TRIG, 1);
	delayMicroseconds(10);
	digitalWrite(TRIG, 0);
	delayMicroseconds(200);
	// wait for echo signal
	//while (digitalRead(ECHO) != 0); //  Wait for burst start
	
	while (digitalRead(ECHO) != 1); //  Wait for ECHO HIGH
	int t1 = micros();	// Get start time (in micro-second)
	while (digitalRead(ECHO) != 0); // Wait for ECHO LOW
	int t2 = micros(); // Get end time.
	// double dist = (t2 - t1) * (340 / 1000000 / 2 * 100); // m to cm
	return Dist (t2 - t1) * 0.017;
}
