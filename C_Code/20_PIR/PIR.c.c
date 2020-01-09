/*
* File name     : PIR.c
* Description   : detect the movement.
* Company       : SunRobotics Technologies
* Website       : www.sunrobotics.co.in
* E-mail        : support@sunrobotics.co.in(For Any Query)
*/
#include <wiringPi.h>
#include <stdio.h>

#define PIR_OUT_PIN 0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(PIR_OUT_PIN, INPUT);

	while(1){
		if(0 == digitalRead(PIR_OUT_PIN)){
			printf("Movement not detected!\n");	
		}else{
			printf("Movement detected!\n");	
		}
	}

	return 0;
}
