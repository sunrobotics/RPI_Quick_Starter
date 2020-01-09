/*
* File name     : blinkingLed.c
* Description   : Make an led blinking.
* Company       : SunRobotics Technologies
* Website       : www.sunrobotics.co.in
* E-mail        : support@sunrobotics.co.in(For Any Query)
*/
#include <wiringPi.h>
#include <stdio.h>

#define  LedPin    11

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiringPi failed, print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(LedPin, OUTPUT);

	while(1){
		digitalWrite(LedPin, LOW);   //led on
		printf("led on...\n");
		delay(500);
		digitalWrite(LedPin, HIGH);  //led off
		printf("...led off\n");
		delay(500);
	}

	return 0;
}

