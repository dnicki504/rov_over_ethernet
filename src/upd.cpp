#include <Ethernet.h>    //Load Ethernet Library
#include <EthernetUdp.h> //Load UDP Library
#include <SPI.h>         //Load the SPI Library

unsigned int localPort = 5000; // Assign a Port to talk over
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
String datReq;   // String for our data
int packetSize;  // Size of Packet
EthernetUDP Udp; // Define UDP Object

void initUdp()
{
    Udp.begin(localPort); // Initialize Udp
    delay(1500);          // delay
    Serial.print("UDP: ");
    Serial.print(Ethernet.localIP());
    Serial.print(":");
    Serial.println(localPort);
}

void udpWatch()
{
    packetSize = Udp.parsePacket(); // Read theh packetSize
    if (packetSize > 0)
    {                                                   // Check to see if a request is present
        Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE); // Reading the data request on the Udp
        String datReq(packetBuffer);                    // Convert packetBuffer array to string datReq
        Serial.println(datReq);

        if (datReq == "Red")
        { // See if Red was requested

            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort()); // Initialize Packet send
            Udp.print("You are Asking for Red");               // Send string back to client
            Udp.endPacket();                                   // Packet has been sent
        }
        if (datReq == "Green")
        { // See if Green was requested

            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort()); // Initialize Packet send
            Udp.print("You are Asking for Green");             // Send string back to client
            Udp.endPacket();                                   // Packet has been sent
        }
        if (datReq == "Blue")
        { // See if Red was requested

            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort()); // Initialize Packet send
            Udp.print("You are Asking for Blue");              // Send string back to client
            Udp.endPacket();                                   // Packet has been sent
        }
    }
    memset(packetBuffer, 0, UDP_TX_PACKET_MAX_SIZE);
}