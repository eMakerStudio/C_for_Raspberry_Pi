/************************************************
* Filename    : relay.c
* Description : Testing the Relay.
* Author      : eMaker Studio
* E-mail      : emaker-studio@goprogramming.space
* website     : emaer-studio.goprogramming.space
* Date        : 2016/08/05
* License	  : MIT 
*************************************************/

#include <wiringPi.h>
#include <stdio.h>

#define RelayPin 0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(RelayPin, OUTPUT);

	while(1){
		digitalWrite(RelayPin, LOW);  //relay off
		delay(500);                   //delay
		digitalWrite(RelayPin, HIGH); //relay on
		delay(500);                   //delay
	}

	return 0;
}

