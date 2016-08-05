/**********************************************************************
* Filename    : beep.c
* Description : Make a buzzer sound.
* Author      : eMaker Studio
* E-mail      : emaker-studio@goprogramming.space
* website     : emaer-studio.goprogramming.space
* Date        : 2016/08/05
* License	  : MIT 
*************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define BeepPin 0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(BeepPin, OUTPUT);   //set GPIO0 output

	while(1){
		digitalWrite(BeepPin, LOW);  //beep on
		delay(100);                  //delay
		digitalWrite(BeepPin, HIGH); //beep off
		delay(100);                  //delay
	}

	return 0;
}

