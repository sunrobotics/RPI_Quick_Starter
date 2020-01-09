/*
* File name     : breathingLed.c
* Description   : control the brightness of led by PWM.
* Company       : SunRobotics Technologies
* Website       : www.sunrobotics.co.in
* E-mail        : support@sunrobotics.co.in(For Any Query)
*/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin    12

int main(void)
{
	int i;

	if(wiringPiSetup() < 0){ //when initialize wiringPi failed, print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(LedPin, PWM_OUTPUT);//pwm output mode

	while(1){
		for(i=0;i<1024;i++){
			pwmWrite(LedPin, i);
			delay(2);
		}
		delay(1000);
		for(i=1023;i>=0;i--){
			pwmWrite(LedPin, i);
			delay(2);
		}
	}

	return 0;
}
