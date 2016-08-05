/***************************************************
* Filename    : lcd1602.c
* Description : LCD display 1602
* Author      : eMaker Studio
* E-mail      : emaker-studio@goprogramming.space
* website     : emaer-studio.goprogramming.space
* Date        : 2016/08/05
* License	  : MIT 
* 
* D4---GPIO6
* D5---GPIO5
* D6---GPIO4
* D7---GPIO1
* RS---GPIO2
* RW---GND
* CE---GPIO3

* gcc lcd1602_2.c -o lcd1602 -wiringPiDev -lwiringPi

*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <lcd.h>

const unsigned char Buf[] = "---EMAKER STUDIO---";
const unsigned char myBuf[] = "  goprogramming.space";

int main(void)
{
	int fd;
	int i;
	if (wiringPiSetup() == -1){
		exit(1);
	}

	fd = lcdInit(2,16,4, 2,3, 6,5,4,1,0,0,0,0); //see /usr/local/include/lcd.h
	printf("%d", fd);
	if (fd == -1){
		printf("lcdInit 1 failed\n") ;
		return 1;
	}
	sleep(1);

	lcdClear(fd);
	lcdPosition(fd, 0, 0); 
	lcdPuts(fd, "Welcom To--->");

	lcdPosition(fd, 0, 1); 
	lcdPuts(fd, "  sunfounder.com");

	sleep(1);
	lcdClear(fd);

	while(1){
		for(i=0;i<sizeof(Buf)-1;i++){
			lcdPosition(fd, i, 1);
			lcdPutchar(fd, *(Buf+i));
			delay(200);
		}
		lcdPosition(fd, 0, 1); 
		lcdClear(fd);
		sleep(0.5);
		for(i=0; i<16; i++){
			lcdPosition(fd, i, 0);
			lcdPutchar(fd, *(myBuf+i));
			delay(100);
		}
	}

	return 0;
}
