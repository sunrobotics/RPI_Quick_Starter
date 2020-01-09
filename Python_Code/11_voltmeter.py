#!/usr/bin/env python
#-----------------------------------------------------------
# File name     : 11_Voltmeter.py
# Description   : a simple voltmeter
# Company       : SunRobotics Technologies
# Website       : www.sunrobotics.co.in
# E-mail        : support@sunrobotics.co.in(For Any Query)
#-----------------------------------------------------------
import ADC0832
import time

def init():
	ADC0832.setup()

def loop():
	while True:
		res = ADC0832.getResult()
		v = res * (3.3 / 255)
		print 'Current voltage: %.2f V' % v
		time.sleep(0.2)

if __name__ == '__main__':
	init()
	try:
		loop()
	except KeyboardInterrupt: 
		ADC0832.destroy()
		print 'The end !'
