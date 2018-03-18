#include <IRsend.h>
//https://github.com/markszabo/IRremoteESP8266
#include <IRremoteESP8266.h>
//https://github.com/tzapu/WiFiManager
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <DNSServer.h>
#include <WiFiManager.h>

#define IR_SEND_PIN D2
#define DELAY_BETWEEN_COMMANDS 200

IRsend irsend(IR_SEND_PIN);

ESP8266WebServer server(80);

const int led = BUILTIN_LED;
const char *webpage = 
#include "WebPage.h"
;

void setup(void){
  irsend.begin();
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
  Serial.begin(115200);
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;

  wifiManager.autoConnect("ArunavAP", "XXXXXXXX");
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS Responder Started");
  }
  setupServer();
}

void loop(void){
  server.handleClient();
}

void handleRoot() {
  digitalWrite(led, 0);
  server.send(200, "text/html", webpage);
  digitalWrite(led, 1);
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 1);
}

void setupServer(){
  // server route
    server.on("/", handleRoot);
  //server route
    server.on("/dth", [](){
    Serial.println("DTH on/off");
    irsend.sendNEC(0x6F948B7, 32);
    delay(50);
    server.send(200, "text/plain", "DTH");
  });
  
  server.on("/av", [](){
    Serial.println("Audio Video");
    irsend.sendSAMSUNG(0xE0E0807F, 32);
    delay(50);
    server.send(200, "text/plain", "AV");
  });
  
  server.on("/tv", [](){
    Serial.println("TV on/off");
    irsend.sendSAMSUNG(0xE0E040BF, 32);
    delay(50);
    server.send(200, "text/plain", "TV");
  });
  
  server.on("/ch1", [](){
    Serial.println("Channel1");
  irsend.sendNEC(0x6F9807F, 32);
    delay(DELAY_BETWEEN_COMMANDS);
    irsend.sendNEC(0x6F900FF, 32);
    delay(DELAY_BETWEEN_COMMANDS);
    irsend.sendNEC(0x6F9906F, 32);
    server.send(200, "text/plain", "Sony");
  });
  
  server.on("/ch2", [](){
    Serial.println("Channel2");
  irsend.sendNEC(0x6F9C03F, 32);
    delay(DELAY_BETWEEN_COMMANDS);
    irsend.sendNEC(0x6F9A05F, 32);
    delay(DELAY_BETWEEN_COMMANDS);
    irsend.sendNEC(0x6F9807F, 32);
    server.send(200, "text/plain", "NDTV");
  });
  
  server.on("/ch3", [](){
    Serial.println("Channel3");
  irsend.sendNEC(0x6F910EF, 32);
    delay(DELAY_BETWEEN_COMMANDS);
    irsend.sendNEC(0x6F9C03F, 32);
    delay(DELAY_BETWEEN_COMMANDS);
    irsend.sendNEC(0x6F9807F, 32);
    server.send(200, "text/plain", "OTV");
  });

  server.on("/n", [](){
    Serial.println("UP");
    irsend.sendNEC(0x6F9FA05, 32);
    delay(50);
    server.send(200, "text/plain", "UP");
  });
  
  server.on("/w", [](){
    Serial.println("West");
    irsend.sendNEC(0x6F99A65, 32);
    delay(50);
    server.send(200, "text/plain", "West");
  });
  
  server.on("/ok", [](){
    Serial.println("OK");
    irsend.sendNEC(0x6F906F9, 32);
    delay(50);
    server.send(200, "text/plain", "OK");
  });
  
  server.on("/e", [](){
    Serial.println("East");
    irsend.sendNEC(0x6F91AE5, 32);
    delay(50);
    server.send(200, "text/plain", "East");
  });
  
  server.on("/s", [](){
    Serial.println("Down");
    irsend.sendNEC(0x6F92AD5, 32);
    delay(50);
    server.send(200, "text/plain", "Down");
  });

  server.on("/back", [](){
    Serial.println("Back");
    irsend.sendNEC(0x6F99867, 32);
    delay(50);
    server.send(200, "text/plain", "Back");
  });
  
  server.on("/close", [](){
    Serial.println("Close");
    irsend.sendNEC(0x6F9DA25, 32);
    delay(50);
    server.send(200, "text/plain", "Close");
  });
  
  server.on("/menu", [](){
    Serial.println("Menu");
    irsend.sendNEC(0x6F9E21D, 32);
    delay(50);
    server.send(200, "text/plain", "Menu");
  });
  server.on("/chnup", [](){
    Serial.println("Channel Up");
    irsend.sendNEC(0x6F9D827, 32);
    delay(50);
    server.send(200, "text/plain", "Channel Up");
  });
  
  server.on("/mute", [](){
    Serial.println("Mute");
    irsend.sendNEC(0x6F908F7, 32);
    delay(50);
    server.send(200, "text/plain", "Mute");
  });
  
  server.on("/volup", [](){
    Serial.println("Volume Up");
    irsend.sendNEC(0xFFFFFFFF, 32);
    delay(100);
    irsend.sendNEC(0x6F958A7, 32);
    delay(100);
    irsend.sendNEC(0xFFFFFFFF, 32);
    delay(50);
    server.send(200, "text/plain", "Volume Up");
  });
  
  server.on("/chndn", [](){
    Serial.println("Channel Down");
    irsend.sendNEC(0x6F9F807, 32);
    delay(50);
    server.send(200, "text/plain", "Channel Down");
  });
  
  server.on("/info", [](){
    Serial.println("Info");
    irsend.sendNEC(0x6F94AB5, 32);
    delay(50);
    server.send(200, "text/plain", "Info");
  });
  
  server.on("/voldn", [](){
    Serial.println("Vloume Down");
    irsend.sendNEC(0xFFFFFFFF, 32);
    delay(100);
    irsend.sendNEC(0x6F97887, 32);
    delay(100);
    irsend.sendNEC(0xFFFFFFFF, 32);
    delay(50);
    server.send(200, "text/plain", "Vloume Down");
  });
  
  server.on("/red", [](){
    Serial.println("Red");
    irsend.sendNEC(0x6F9C837, 32);
    delay(50);
    server.send(200, "text/plain", "Red");
  });
  
  server.on("/green", [](){
    Serial.println("Green");
    irsend.sendNEC(0x6F99867, 32);
    delay(50);
    server.send(200, "text/plain", "Green");
  });
  
  server.on("/yellow", [](){
    Serial.println("Yellow");
    irsend.sendNEC(0x6F9C639, 32);
    delay(50);
    server.send(200, "text/plain", "Yellow");
  });
  
  server.on("/blue", [](){
    Serial.println("Blue");
    irsend.sendNEC(0x6F9E817, 32);
    delay(50);
    server.send(200, "text/plain", "Blue");
  });

  server.on("/c1", [](){
    Serial.println("1");
    irsend.sendNEC(0x6F9807F, 32);
    delay(50);
    server.send(200, "text/plain", "1");
  });
  
  server.on("/c2", [](){
    Serial.println("2");
    irsend.sendNEC(0x6F940BF, 32);
    delay(50);
    server.send(200, "text/plain", "2");
  });
  
  server.on("/c3", [](){
    Serial.println("3");
    irsend.sendNEC(0x6F9C03F, 32);
    delay(50);
    server.send(200, "text/plain", "3");
  });
  
  server.on("/c4", [](){
    Serial.println("4");
    irsend.sendNEC(0x6F920DF, 32);
    delay(50);
    server.send(200, "text/plain", "4");
  });
  
  server.on("/c5", [](){
    Serial.println("5");
    irsend.sendNEC(0x6F9A05F, 32);
    delay(50);
    server.send(200, "text/plain", "5");
  });
  
  server.on("/c6", [](){
    Serial.println("6");
    irsend.sendNEC(0x6F9609F, 32);
    delay(50);
    server.send(200, "text/plain", "6");
  });
  
  server.on("/c7", [](){
    Serial.println("7");
    irsend.sendNEC(0x6F9E01F, 32);
    delay(50);
    server.send(200, "text/plain", "7");
  });
  
  server.on("/c8", [](){
    Serial.println("8");
    irsend.sendNEC(0x6F910EF, 32);
    delay(50);
    server.send(200, "text/plain", "8");
  });
  
  server.on("/c9", [](){
    Serial.println("9");
    irsend.sendNEC(0x6F9906F, 32);
    delay(50);
    server.send(200, "text/plain", "9");
  });
  
  server.on("/x", [](){
    Serial.println("*");
    irsend.sendNEC(0x6F98877, 32);
    delay(50);
    server.send(200, "text/plain", "x");
  });
  
  server.on("/c0", [](){
    Serial.println("0");
    irsend.sendNEC(0x6F900FF, 32);
    delay(50);
    server.send(200, "text/plain", "0");
  });
  
  server.on("/hash", [](){
    Serial.println("#");
    irsend.sendNEC(0x6F9C23D, 32);
    delay(50);
    server.send(200, "text/plain", "#");
  });
  
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP Server Started");
}
