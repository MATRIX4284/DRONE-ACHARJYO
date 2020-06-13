//Control the DJI Tello Drone From a Pre-Complied Set of Commands using Esp8266 Wifi Module.
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

void execute(String command) {
    Serial.println("Contents:");
    Serial.println(command);
    //String command = "command";
    int buffSize = command.length();
    
    //const unsigned char *buff = (const unsigned char *)malloc(buffSize);
    //command.toCharArray(buff, buffSize);
    //buff_c = buff.c_str()
    const  char *buff = (const  char *)command.c_str();
    
    Udp.beginPacket(TELLO_IP, telloPort);
    Udp.write(buff);
    Udp.endPacket();
    delay(2000);
}

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

    String command1 = "command" ;
    execute("command");

    String command2 = "takeoff" ;
    execute(command2);

    String command3 = "flip l" ;
    execute(command3);

    String command4 = "land" ;
    execute(command4);


}




void loop() 
{
  while(Serial.available()) 
  {
    String command1 = "command" ;
    execute("command");

    String command2 = "takeoff" ;
    execute(command2);

    String command3 = "flip l" ;
    execute(command3);

    String command4 = "land" ;
    execute(command4);




    
  }

  
}

/*
  test (shell/netcat):
  --------------------
    nc -u 192.168.esp.address 8888
*/
