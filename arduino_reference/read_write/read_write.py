#!/usr/bin/env python

import serial

s = serial.Serial("/dev/ttyACM0", 9600);
s.write(b'hello')
s.close();
