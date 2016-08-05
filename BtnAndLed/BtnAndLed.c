/************************************************
* Filename    : BtnAndLed.c
* Description : Controll LED by button.
* Author      : eMaker Studio
* E-mail      : emaker-studio@goprogramming.space
* website     : emaer-studio.goprogramming.space
* Date        : 2016/08/05
* License	  : MIT 
*************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin    0
#define ButtonPin 1

int main(void)
{   /* if initialize wiring failed, print message to screen */
	if(wiringPiSetup() == -1){ 
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);

	/* pull up to 3.3V or 5V, gives GPIO1 more stability */
	pullUpDnControl(ButtonPin, PUD_UP);  
	while(1){
		digitalWrite(LedPin, HIGH);
		/* indicate that the button has pressed */
		if(digitalRead(ButtonPin) == 0){ 
			digitalWrite(LedPin, LOW);   //led on
		}
	}

	return 0;
}

