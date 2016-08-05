/************************************************
* Filename    : servo_test.c
* Description : Testing servo motor
* Author      : eMaker Studio
* E-mail      : emaker-studio@goprogramming.space
* website     : emaer-studio.goprogramming.space
* Date        : 2016/08/05
* License	  : MIT 
*************************************************/

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd;
	unsigned char pos = 0;
	unsigned char buf[4] = {0};
	unsigned char *buf1 = "hello\n";

	fd = serialOpen("/dev/ttyAMA0", 9600);	

	unsigned char tmp;

	while(1){
	//	scanf("%d", &pos);
	//	snprintf(buf, 4, "%d", pos);
		//printf("*** %s\n",buf);
		serialPrintf(fd, "120\r\n");
		sleep(1);
		serialPrintf(fd, "20\r\n");
		sleep(1);
		serialPrintf(fd, "150\r\n");
		sleep(1);
		delay(2500);
	}

	serialClose(fd);

	return 0;
}

