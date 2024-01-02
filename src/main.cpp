/*
 Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino WIZnet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi

 */

#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

void udpWatch();
void initUdp();
void initServer(byte mac[], int ip[]);
void srvWatch();
void initEthernet();

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ipAdr(192, 168, 0, 150);
int ip[] = {192, 168, 1, 178};
// http://192.168.0.150/

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  initEthernet();
  initServer(mac, ip);
  initUdp();
}

void initEthernet()
{
  Ethernet.init(10);

  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ipAdr);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware)
  {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true)
    {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF)
  {
    Serial.println("Ethernet cable is not connected.");
  }
}

void loop()
{

  udpWatch();
  srvWatch();
}