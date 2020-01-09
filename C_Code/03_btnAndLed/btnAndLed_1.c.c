/*
* File name   : btnAndLed.c
* Description : Toggle a led by button.
* Company     : SunRobotics Technologies
* Website     : www.sunrobotics.co.in
* E-mail      : support@sunrobotics.co.in(For Any Query)
*/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin    11
#define ButtonPin 12

int status = 1;

void myISR(void)
{
	status = !status;	
}

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);

	pullUpDnControl(ButtonPin, PUD_UP);
	
	if(wiringPiISR(ButtonPin, INT_EDGE_FALLING, myISR) < 0){
		printf("ISR setup error!\n");
		return -1;
	}

	while(1){
		digitalWrite(LedPin, status);
	}

	return 0;
}
