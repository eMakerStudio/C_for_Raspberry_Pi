/*************************************************
* Filename    : breathLed.c
* Description : Make LED breath.
* Author      : eMaker Studio
* E-mail      : emaker-studio@goprogramming.space
* website     : emaer-studio.goprogramming.space
* Date        : 2016/08/05
* License	  : MIT 
*************************************************/

#include <wiringPi.h>
#include <stdio.h>

#define LedPin    1

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, PWM_OUTPUT);//pwm output mode

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|              Breath LED              |\n");
	printf("|    ------------------------------    |\n");
	printf("|         LED connect to GPIO0         |\n");
	printf("|                                      |\n");
	printf("|            Make LED breath           |\n");
	printf("|                                      |\n");
	printf("|                         eMaker Studio|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	while(1){
		printf("Breath on\n");
		for(i=0;i<1024;i++){
			pwmWrite(LedPin, i);
			delay(2);
		}
		delay(1000);
		printf("Breath off\n");
		for(i=1023;i>=0;i--){
			pwmWrite(LedPin, i);
			delay(2);
		}
	}

	return 0;
}

