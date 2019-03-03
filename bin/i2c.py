#!/usr/bin/python

import smbus
import time

bus = smbus.SMBus(1)

addr = 0x4

var = 0
while True:
	print("Starting loop ")	
	bus.write_byte(addr, var)
	print "I sent a message to arduino"
	time.sleep(0.5)

	num = bus.read_byte(addr)
	print "Arduino sent us", num
	print
	
	var = var + 1
	if addr == 0x4:
		addr = 0x6
	else:
		addr = 0x4
