#!/usr/bin/env ruby
require 'rubygems'
require 'serialport'

ser = SerialPort.new("/dev/ttyACM0", 9600, 8, 1, SerialPort::NONE)

ser.write "ferretland"
while true
    puts ser.readchar
end
ser.close
