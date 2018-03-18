#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// Add this library: https://github.com/markszabo/IRremoteESP8266
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "ssid.h"

#define IR_SEND_PIN D2

#define DELAY_BETWEEN_COMMANDS 200

IRsend irsend(IR_SEND_PIN);

ESP8266WebServer server(80);

const int led = BUILTIN_LED;

String rowDiv = "<div class=\"row\" style=\"padding-bottom:1em\">\n";
String endDiv = "    </div>\n";

// Buttons are using the bootstrap grid for sizing - http://getbootstrap.com/css/#grid
String generateButton(String colSize, String id, String btnStyle, String text) {
  return  "<div class=\"" + colSize + "\">\n" +
          "    <button id=\"" + id + "\" type=\"button\" class=\"" + btnStyle + "\" style=\"width: 100%\" onclick='makeAjaxCall(\"" + id + "\")'>" + text + "</button>\n" +
          "</div>\n";
}

String generateGlyphicon(String classStr){
  return "<span class=\"" + classStr + "\"></span></button>\n";
}

void handleRoot() {
  digitalWrite(led, 0);
  String website = "<!DOCTYPE html>\n";
  website = website + "<html>\n";
  website = website + "<head>\n";
  website = website + "<meta charset=\"utf-8\">\n";
  website = website + "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
  website = website + "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
  website = website + "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\">\n";
  website = website + "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js\"></script>\n";
  website = website + "<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"></script>\n";
  website = website + "<script> function makeAjaxCall(url){$.ajax({\"url\": url})}</script>\n";
  website = website + "</head>\n";
  website = website + "<body>\n";
  website = website + "</br>\n";
  website = website + "<div class=\"container-fluid\">\n";
  website = website + "<!-- Power Controls -->\n";
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "dth", "btn btn-danger btn-sm", "DTH");
  website = website + generateButton("col-xs-4", "av", "btn btn-success btn-sm", "AV");
  website = website + generateButton("col-xs-4", "tv", "btn btn-danger btn-sm", "TV");
  website = website + endDiv;
  website = website + "<!-- Channel Controls -->\n";
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "ch1", "btn btn-warning btn-sm", "Sony");
  website = website + generateButton("col-xs-4", "ch2", "btn btn-warning btn-sm", "NDTV");
  website = website + generateButton("col-xs-4", "ch3", "btn btn-warning btn-sm", "OTV");
  website = website + endDiv;
  website = website + "<!-- DTH Controls -->\n";
  website = website + rowDiv;
  website = website + generateButton("col-xs-offset-4 col-xs-4", "n", "btn", generateGlyphicon("glyphicon glyphicon-triangle-top"));
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "w", "btn", generateGlyphicon("glyphicon glyphicon-triangle-left"));
  website = website + generateButton("col-xs-4", "ok", "btn", "OK");
  website = website + generateButton("col-xs-4", "e", "btn", generateGlyphicon("glyphicon glyphicon-triangle-right"));
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-offset-4 col-xs-4", "s", "btn", generateGlyphicon("glyphicon glyphicon-triangle-bottom"));
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "back", "btn btn-warning btn-xs", generateGlyphicon("glyphicon glyphicon-arrow-left"));
  website = website + generateButton("col-xs-4", "close", "btn btn-danger btn-xs", generateGlyphicon("glyphicon glyphicon-remove"));
  website = website + generateButton("col-xs-4", "menu", "btn btn-danger btn-xs", generateGlyphicon("glyphicon glyphicon-th-list"));
  website = website + endDiv;
  website = website + "<!-- Channel/Volume Controls -->\n";
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "chnup", "btn btn-primary", generateGlyphicon("glyphicon glyphicon-plus"));
  website = website + generateButton("col-xs-4", "mute", "btn btn-danger", generateGlyphicon("glyphicon glyphicon-volume-off"));
  website = website + generateButton("col-xs-4", "volup", "btn btn-primary", generateGlyphicon("glyphicon glyphicon-volume-up"));
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "chndn", "btn btn-primary", generateGlyphicon("glyphicon glyphicon-minus"));
  website = website + generateButton("col-xs-4", "info", "btn btn-info", generateGlyphicon("glyphicon glyphicon-info-sign"));
  website = website + generateButton("col-xs-4", "voldn", "btn btn-primary", generateGlyphicon("glyphicon glyphicon-volume-down"));
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-3", "red", "btn btn-danger btn-xs", "&nbsp;");
  website = website + generateButton("col-xs-3", "green", "btn btn-success btn-xs", "&nbsp;");
  website = website + generateButton("col-xs-3", "yellow", "btn btn-warning btn-xs", "&nbsp;");
  website = website + generateButton("col-xs-3", "blue", "btn btn-primary btn-xs", "&nbsp;");
  website = website + endDiv;
  website = website + "<!-- Numbers -->\n";
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "c1", "btn btn-infobtn btn-info", "1");
  website = website + generateButton("col-xs-4", "c2", "btn btn-info", "2");
  website = website + generateButton("col-xs-4", "c3", "btn btn-info", "3");
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "c4", "btn btn-info", "4");
  website = website + generateButton("col-xs-4", "c5", "btn btn-info", "5");
  website = website + generateButton("col-xs-4", "c6", "btn btn-info", "6");
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "c7", "btn btn-info", "7");
  website = website + generateButton("col-xs-4", "c8", "btn btn-info", "8");
  website = website + generateButton("col-xs-4", "c9", "btn btn-info", "9");
  website = website + endDiv;
  website = website + rowDiv;
  website = website + generateButton("col-xs-4", "x", "btn btn-info", "&#8727;");
  website = website + generateButton("col-xs-4", "c0", "btn btn-info", "0");
  website = website + generateButton("col-xs-4", "hash", "btn btn-info", "#");
  website = website + endDiv;
  website = website + "</body>\n";
  website = website + "</html>\n";

  server.send(200, "text/html", website);
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

void setup(void){
  irsend.begin();
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS Responder Started");
  }

  server.on("/", handleRoot);

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

void loop(void){
  server.handleClient();
}
