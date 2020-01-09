#!/usr/bin/env python
#-----------------------------------------------------------
# File name     : 21_motor.py
# Company       : SunRobotics Technologies
# Website       : www.sunrobotics.co.in
# E-mail        : support@sunrobotics.co.in(For Any Query)
#-----------------------------------------------------------

# Import required modules
import time
import RPi.GPIO as GPIO


# Declare the GPIO settings
GPIO.setmode(GPIO.BOARD)

# set up GPIO pins
GPIO.setup(12, GPIO.OUT) # Connected to PWMA
GPIO.setup(16, GPIO.OUT) # Connected to AIN2
GPIO.setup(8, GPIO.OUT) # Connected to AIN1

# Drive the motor clockwise
GPIO.output(8, GPIO.HIGH) # Set AIN1
GPIO.output(16, GPIO.LOW) # Set AIN2

# Set the motor speed
GPIO.output(12, GPIO.HIGH) # Set PWMA

# Wait 5 seconds
time.sleep(5)

# Drive the motor counterclockwise
GPIO.output(8, GPIO.LOW) # Set AIN1
GPIO.output(16, GPIO.HIGH) # Set AIN2

# Set the motor speed
GPIO.output(12, GPIO.HIGH) # Set PWMA

# Wait 5 seconds
time.sleep(5)

# Reset all the GPIO pins by setting them to LOW
GPIO.output(8, GPIO.LOW) # Set AIN1
GPIO.output(16, GPIO.LOW) # Set AIN2
GPIO.output(12, GPIO.LOW) # Set PWMA
