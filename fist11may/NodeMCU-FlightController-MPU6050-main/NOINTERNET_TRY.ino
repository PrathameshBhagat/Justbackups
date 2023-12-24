#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const char* ssid = "EsP";  //YOUR SSID
const char* password = "11111111";  //YOUR WIFI PSSWORD
ESP8266WebServer server(80);
void doi(){
  Serial.print(server.arg("s"));server.send(200,"text/html","<h1>Hello </h1>"+server.arg("s"));
}
void n(){
server.send(200,"text/html","<h1>Hello </h1>");
}
void setup() {
    Serial.begin(115200);
  WiFi.softAP(ssid,password);
  IPAddress IP =WiFi.softAPIP();
  Serial.print(" IP   :------------");
    Serial.print(IP);
  Serial.print("\nhttp://");    //URL IP to be typed in mobile/desktop browser
  Serial.print(WiFi.localIP());
  Serial.println("/");

  server.on("/",n);
  server.on("/l",doi);
  server.begin();
}
void loop() {
server.handleClient();
}