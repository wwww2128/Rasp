#include <wiringPi.h>
#include <softTone.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#define SPKR 	6
#define TOTAL	32

void cleanup(int signum) {
    // LED 끄기
    digitalWrite(SPKR, LOW);
    printf("LED가 꺼졌습니다.\n");
	 exit(0);
}

int keynote[] = {
	391, 391, 440, 440, 391, 391, 329.63, 329.63, \
	391, 391, 329.63, 329.63, 293.66, 293.66, 293.66, 0, \
	391, 391, 440, 440, 391, 391, 329.63, 329.63, \
	391, 329.63, 293.66, 329.63, 261.63, 261.63, 261.63, 0
};

int musicPlay()
{
	int i;

	softToneCreate(SPKR);

	for(i = 0; i < TOTAL; ++i)
	{
		softToneWrite(SPKR, keynote[i]);
		delay(280);
	}
	return 0;
}

int main()
{
	wiringPiSetup();
	musicPlay();
	signal(SIGINT, cleanup);
	return 0;
}

