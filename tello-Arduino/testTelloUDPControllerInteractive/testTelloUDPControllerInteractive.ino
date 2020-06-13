//Control the DJI Tello Drone Interactively using Esp8266 Wifi Module leveraging the Serial Interface .Ideal for machine to machine communication.
//Author:Kaustav Mukherjee

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#ifndef STASSID
#define TELLO_ID "TELLO-FDA553"
#define TELLO_IP "192.168.10.1"


#endif

unsigned int telloPort = 8889;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE + 1]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged\r\n";       // a string to send back

WiFiUDP Udp;

void setup() {
  Serial.begin(115200);
  char a = Serial.read();
  WiFi.mode(WIFI_STA);
  WiFi.begin(TELLO_ID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}


void execute(String command) {
  Serial.println("Contents:");
    Serial.println(command);
    int buffSize = command.length();
    char *buff = (char *)malloc(buffSize);
    command.toCharArray(buff, buffSize);

    
    Udp.beginPacket(TELLO_IP, telloPort);
    Udp.write(buff);
    Udp.endPacket();
}

void loop() 
{
  while(Serial.available()) 
  {
    String command_buffer = Serial.readString() ;
    //char c[2] = Serial.readString();
    Serial.println(command_buffer);
    //strncpy(b, c, 2);
  
    execute(command_buffer);


    
  }

  
}

/*
  test (shell/netcat):
  --------------------
    nc -u 192.168.esp.address 8888
*/
