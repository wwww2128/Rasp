#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main(void)
{
    printf("\033[2J"); //[2J 화면클리어
    int fd = wiringPiI2CSetup(0x48);    // Device reset


    while(1)
    {
        wiringPiI2CWrite(fd, 0);        // ch00 (PR) select
        int v1 = wiringPiI2CRead(fd);   // int v1 = (wiringPiI2CRead(fd) 80) / 255;
        int x = ((float)(v1/255.0)*80.0);
        delay(100);

        wiringPiI2CWrite(fd, 1);        // ch01 (TR) select
        int v2 = wiringPiI2CRead(fd);       // clear
        int y = ((float)(v2/255.0)*24.0);
        delay(100);

        printf("\033[%d;%dH(%d %d)\n",y,x,x,y); //[1;1H -> [y;xH 커서를 제일 위에 위치에 저장
        delay(500);
        printf("\033[2J"); //[2J 화면클리어


    }
        return 0;
}
