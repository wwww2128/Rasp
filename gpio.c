#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#define RED	 0
#define GREEN	 1
#define YELLOW	 2
#define SW	 3
#define STOP	 4
int mode = 0;
int intv = 0;
int tim;
int ps[40];
//pin state, pin number ; 40 // default 0(reset 0)

void Toggle(int pin)
{
    ps[pin] = !ps[pin];  // toggle
    digitalWrite(pin,ps[pin]);
}

void stopisr()
{
	digitalWrite(RED, LOW);
	digitalWrite(GREEN, LOW);
	digitalWrite(YELLOW, LOW);
	printf("done \n");
}

void gpioisr()
{
       if(++intv > 8) intv = 0;
       printf("GPIO interrupt occured..\n");
}

int main()
{
    wiringPiSetup();    // pin in / out(wPi) reset function
    pinMode(RED , OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(SW, INPUT);
    wiringPiISR(SW, INT_EDGE_FALLING, gpioisr);
    wiringPiISR(STOP, INT_EDGE_FALLING, stopisr);// resister GPIO ISR


    for(;;) //for(;;) = while(1)
    {
	tim = (9-intv)*100;

        if(mode)
        {
            Toggle(0);     delay(tim);
            Toggle(1);     delay(tim);
            Toggle(2);     delay(tim);
        }
        else
        {
            Toggle(2);     delay(tim);
            Toggle(1);     delay(tim);
            Toggle(0);     delay(tim);
        }


    }
    return 0;
}
