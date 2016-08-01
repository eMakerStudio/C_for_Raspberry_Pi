//blink.c

#include <wiringPi.h>
#include <stdio.h>
#define LedPin 0

int main(void)
{
wiringPiSetup();

	printf("\n");
	printf("========================================\n");
	printf("|              Blink LED               |\n");
	printf("|    ------------------------------    |\n");
	printf("|         LED connect to GPIO0         |\n");
	printf("|                                      |\n");
	printf("|        LED will Blink at 500ms       |\n");
	printf("|                                      |\n");
	printf("|                     by  eMaker Studio|\n");
	printf("========================================");
	printf("\n");
	printf("\n");


pinMode(LedPin, OUTPUT);

while(1){
digitalWrite(LedPin, LOW); //led on
printf("led on...\n");
delay(500);
digitalWrite(LedPin, HIGH); //led off
printf("...led off\n");
delay(500);
}
return 0;
}

