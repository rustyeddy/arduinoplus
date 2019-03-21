#!/usr/bin/python

import smbus
import time
import sys

bus = smbus.SMBus(1)

addr = 0x4

swap = True

var = 0
while True:
	try:
		bus.write_byte(addr, var)
		print "I sent a message addr {} msg {}".format(addr, var)
		time.sleep(0.1)

		num = bus.read_byte(addr)
		print "   arduino {} sent us {}".format(addr, num)
		print
	except:
		e = sys.exc_info()[0]
		print "Failed addr {} msg {}".format(addr, var)	
		time.sleep(2)
	
	var = var + 1
	if swap:
		if addr == 0x4:
			addr = 0x6
		elif addr == 0x6:
			addr = 0x8
		else:
			addr = 0x6
 
			
