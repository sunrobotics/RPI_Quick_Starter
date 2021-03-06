#!/usr/bin/env python
###############################################################
 # File name     : thermistor.c
 # Description   : convert the analog value to a number.
 # Company       : SunRobotics Technologies
 # Website       : www.sunrobotics.co.in
 # E-mail        : support@sunrobotics.co.in(For Any Query)
 ##############################################################
import ADC0832
import time

def init():
	ADC0832.setup()

def loop():
	while True:
		res = ADC0832.getResult()
		if res < 0:
			res = 0
		if res > 100:
			res = 100
		print 'res = %d' % res
		time.sleep(0.2)

if __name__ == '__main__':
	init()
	try:
		loop()
	except KeyboardInterrupt: 
		ADC0832.destroy()
		print 'The end !'
