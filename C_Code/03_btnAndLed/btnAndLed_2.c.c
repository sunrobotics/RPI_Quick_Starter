/*
* File name   : btnAndLed.c
* Description : Toggle a led by button.
* Company     : SunRobotics Technologies
* Website     : www.sunrobotics.co.in
* E-mail      : support@sunrobotics.co.in(For Any Query
*/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin    11
#define ButtonPin 12

int status = 1;

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);

	pullUpDnControl(ButtonPin, PUD_UP);

	while(1){
		if(digitalRead(ButtonPin) == 0){
			delay(10);
			if(digitalRead(ButtonPin) == 0){
				status = !status;
				digitalWrite(LedPin, status);   //toggle the status of led	
				printf("The status of led is toggled !\n");
			}
			while(!digitalRead(ButtonPin));
		}
	}

	return 0;
}
