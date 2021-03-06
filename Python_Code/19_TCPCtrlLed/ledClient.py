#!/usr/bin/env python
#-----------------------------------------------------------
# File name   : 19_Controlling an LED through LAN.py
# Company       : SunRobotics Technologies
# Website       : www.sunrobotics.co.in
# E-mail        : support@sunrobotics.co.in(For Any Query)
#-----------------------------------------------------------
from socket import *

HOST = '192.168.1.11'    # Server(Raspberry Pi) IP address
PORT = 8080
BUFSIZ = 1024            # buffer size
ADDR = (HOST, PORT)

tcpCliSock = socket(AF_INET, SOCK_STREAM)   # Create a socket
tcpCliSock.connect(ADDR)                    # Connect with the server

def loop():
	while True:
		cmd = raw_input('input cmd : ')
		tcpCliSock.send(cmd)

if __name__ == '__main__':
	try:
		loop()
	except KeyboardInterrupt:
		tcpCliSock.close()
