#include <wiringPi.h>
#include <stdio.h>
#define LedPin 0

int main(void)
{
wiringPiSetup();

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

