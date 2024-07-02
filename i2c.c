#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

main()
{
	int fd = wiringPiI2CSetup(0x48); // devicehandle  hex 48 

	int val, val2, val3;
	float f, f2, f3;
	while(1)
	{
		wiringPiI2CWrite(fd, 0); // ch0
		val = wiringPiI2CRead(fd); // int 반환 
		f = (float)((val/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(fd, 1); // ch1
		val2 = wiringPiI2CRead(fd); // int 반환 
		f2 = (float)((val2/255.0)*5.0);
		delay(100);
        
       	wiringPiI2CWrite(fd, 3); // ch03
		val3 = wiringPiI2CRead(fd); // int 반환 
		f3 = (float)((val3/255.0)*5.0);
		printf("ADC input level = %d %d %d (%4.1fV, %4.1f %4.1f)\n",val, val2, val3, f, f2, f3);
		delay(100);
	}
		
}
