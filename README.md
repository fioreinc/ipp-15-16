# ipp-15-16
This repository contains the code responsible for interfacing with the Dextrus Hand and associated pressure sensors via the XBee and Arduino

# Setting up the Development Environment

## Installing ROS
Follow this tutorial to install ROS Indigo on Ubuntu: http://wiki.ros.org/indigo/Installation/Ubuntu

Follow this tutorial to set up the Arduino IDE to work with ROS: http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

## Installing XCTU
Download the Linux version of XCTU here: http://www.digi.com/products/xbee-rf-solutions/xctu-software/xctu#resources
Be sure to run the installer as sudo, and leave the default installation directory: /opt/Digi
After it is installed, use gksudo to run the program. It won't work unless you run it as root.

## Installing Arduino IDE
Download the Arduino IDE from here:https://www.arduino.cc/en/Main/Software

Add this library to the IDE: https://github.com/bogde/HX711

# Communication between XBees

## Configuring the XBees
1. Use the XBee Explorer to connect each XBee to a computer with XCTU installed. 
2. Open up XCTU and click the button in the top left "Add a radio module"
3. Select the port that the Explorer is connected to and press "Finish"
4. Once the XBee is found, click on the "Settings" icon to set the settings as follows:

### For the first XBee:
Pan ID: 6612 (This can be whatever, as long as each XBee has the same value)
Baud Rate: 9600
DH: 0
DL: 1
MY 16 Bit Source Addr: 0

### For the second XBee:
Pan ID: 6612 
Baud Rate:9600
DH: 0
DL: 0
My 16 Bit Source Addr: 1

Once each XBee is configured, leave one connected to the computer and attach the other to the XBee shield that is stacked on the Arduino MEGA.

When writing Arduino Sketches, communication with the XBee works over the hardware serial port (i.e. Serial.write() and Serial.read()). The SoftwareSerial library that a lot of XBee tutorials have you use does NOT work with the shield and the Arduino MEGA.

On the shield, there is a switch that can be in either "DLINE" or "UART" mode. DLINE mode means that the XBee's RX and TX pins are set to free pins on the Arduino, namely 2 and 3. This is where you would use the SoftwareSerial library if the MEGA supported it for pins 2 and 3.  Since it doesn't, the switch will need to be in UART mode (RX and TX connected to pins 0 and 1, the Hardware Serial I/O pins) for the XBee to receive data.

__CAUTION: Be sure the switch is in DLINE mode when uploading sketches to the Arduino. Otherwise the (potentially harmful) data will be sent to the XBee as well as the Arduino.__

### Sending data from computer-connected XBee to Arduino-connected XBee
1. Open Console Mode in XCTU (top right)
2. Click the "Open" button in the top left of the console area. This opens up the communication channel between XBees
3. In the "Send Frames" area, click the plus sign and then click "Create Frame using 'Frames Generator' Tool"
4. Under Frame Type, select "0x01 Tx (Transmit) Request: 16-Bit Address"
5. Under 16-bit Dest Address, enter the address of the XBee connected to the Arduino as a four digit hexadecimal number (i.e. 00 01)
6. For RF data, enter either the ASCII text or HEX bytes you want to transmit and press "OK"
7. A new frame will be created. To send it, select the frame and press the "Send Selected Frame Button"

This data can be read on the Arduino using the standard Serial.available() and Serial.read() function calls. Remember to place the switch in UART mode after the sketch has been uploaded and you want to read data from the XBee.

# Controlling the Robotic Hand

Open `motor_code.ino` within Arduino IDE, and upload to Arduino MEGA microcontroller. Ensure that under the "Tools" toolbar you have selected the correct Board and Port for your microcontroller. Once uploaded, open the Serial Monitor and turn on the power to the motors. The Serial Monitor accepts user input and allows you to send several commands to control the robotic hand. Once a command has been entered the hand will act accordingly, and time and sensor data will be outputted to the serial monitor.

## Commands
- `openclose` - Close all digits of the hand 80%, then open again.
- `reset`     - Reset the position of all motors to 0. This command can be used to halt the execution of other commands.
- `gripCoke`  - Grip 12oz Coke can with predetermined threshold for sensors.
- `gripFullTea` - Grip 23oz tea can " "
- `gripEmptyTea`  - Grip empty tea can " "
- `gripWater` - Grip empty plastic water bottle " "
- `gripEraser`  - Grip whiteboard eraser " "
- `gripThermos` - Grip Fiore Industries coffee thermos " "
- `gripFullWater`- Grip full 16oz water bottle " "
- `downPinky` - Close pinky.
- `downRing`  - Close ring finger.
- `downMiddle`  - Close middle finger.
- `downIndex` - Close index finger.
- `downThumb` - Close thumb.
- `lobo`  - Make lobo hand sign.


## Data Acquisition and Analysis - Python Plot
`python_plot.py` is a Python script to analyze data acquired from an array of pressure sensors on the robotic hand.

 The Arduino Sketch `motor_code.ino` outputs the time elapsed (in milliseconds) and the voltage readings from each pressure sensor to the serial monitor. This data can then be exported to a text file for plotting with Python.

The data in the output text file is formatted line by line as follows: 
```<time>, <thumb sensor>, <index sensor>, <middle finger sensor>, <ring finger sensor>, <pinky sensor>```
This python program opens a specified text file, parses the values in an organized manner, and plots them with Matplotlib's Pyplot.
