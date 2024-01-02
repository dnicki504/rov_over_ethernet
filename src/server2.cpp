// #include <Arduino.h>
// #include <SPI.h>
// #include <Ethernet.h>
// #include <ServerHandler.h>

// EthernetServer server(80);
// ServerHandler responseHandler(NULL, NULL, NULL);

// void initServer(byte mac[], int ip[])
// {
//     Serial.begin(9600);
//     responseHandler = ServerHandler(&server, mac, ip);
//     responseHandler.enableLogs();
// }

// void srvWatch()
// {
//     bool requestReceived = responseHandler.listenRequest();

//     if (requestReceived)
//     {
//         String method = responseHandler.getHttpMethod();
//         Serial.println("request: ");
//         Serial.println(responseHandler.getRequestPath());
//         Serial.print("method: ");
//         Serial.println(method);

//         if (responseHandler.getRequestPath().equals("/") && method.equals("GET"))
//         {
//             responseHandler
//                 .buildResponse(200)
//                 .appendHeaderResponse("Content-Type: text/plain")
//                 .appendHeaderResponse("Connection: close")
//                 .appendBodyResponse("I am ready. Use POST /move with body")
//                 .send();
//         }
//         else if (responseHandler.getRequestPath().equals("/favicon.ico"))
//         {
//             responseHandler.sendNotFoundResponse();
//         }
//         else if (responseHandler.getRequestPath().equals("/move") && method.equals("POST"))
//         {
//             String request = String(responseHandler.getRequestBody());
//             Serial.println(request);
//             responseHandler
//                 .buildResponse(200)
//                 .appendHeaderResponse("Content-Type: text/plain")
//                 .appendHeaderResponse("Connection: close")
//                 .appendBodyResponse(request)
//                 .send();
//         }
//         else
//         {
//             responseHandler.sendNotFoundResponse();
//         }
//     }
// }