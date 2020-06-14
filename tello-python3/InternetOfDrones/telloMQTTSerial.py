##Controlling a drone from internet using Rspberry Pi as the Internet connected hub and using Serial Connection to ESP8266which acts as the Drone Controller.
##Author: Kaustav Mukherjee

import sys
from datetime import datetime
import time

import io
start_time = str(datetime.now())


command="command"

##Setup Serial Port for Connecting to ESP8266 using UART and connecting to its RX & TX.
import serial
 


import paho.mqtt.client as mqtt

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    client.subscribe('tello')
    
    

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    print('chkpt1')
    print(msg.payload.decode())
    a=msg.payload.decode()
    print('chkpt')
    print(a)

    ser1 = serial.Serial('/dev/ttyUSB0',115200)
    ser1.write(a.encode())
    b = ser1.readline()
    print(b)
    ser1.close() 
    


print("hi")
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("192.168.1.100", 1883, 60)
client.loop_forever()












