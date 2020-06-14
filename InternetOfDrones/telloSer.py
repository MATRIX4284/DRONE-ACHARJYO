import sys
from datetime import datetime
import time

import io
start_time = str(datetime.now())


command="land "

##Setup Serial Port for Connecting to ESP8266 using UART and connecting to its RX & TX.
import serial
 

ser1 = serial.Serial('/dev/ttyUSB0',115200)
ser1.write(command.encode())
#ser1.write(b"commando")
#ser1.flush()

a = ser1.readline()
print(a)
ser1.close() 
