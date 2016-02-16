#!/usr/bin/env ruby
require 'rubygems'
require 'serialport'
require 'io/wait'

ser = SerialPort.new("/dev/ttyACM0", 9600, 8, 1, SerialPort::NONE)


ser.write("[init_scale]")
while true
    if ser.ready?
        print ser.readchar
    end
end
ser.close
