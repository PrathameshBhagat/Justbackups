#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h> 
#include "PageIndex.h"
const char* ssid = "ESPServo";  // your SSID
const char* password = "11111111"; //WIFI Password #include <ESP8266WebServer.h>
int Throttle=0;
Servo servo_THROTTLE,servo_YAW,servo_PITCH,servo_ROLL; 
ESP8266WebServer server(80); 
void handleRoot() {
  String s = MAIN_page; 
  server.send(200, "text/html", s); 
}

void handleStick1() {
  String tmp=server.arg("THROTTLE");int temp=tmp.toInt();
  Throttle = map(temp,-100,100,0,180);
  tmp=server.arg("YAW");temp=tmp.toInt();
  int Yaw = map(temp,-100,100,0,180);
  server.send(200, "text/plane", "");
  if(Throttle>=0&&Throttle<=180)servo_THROTTLE.write(Throttle);  
  if(Yaw>=0&&Yaw<=180)servo_YAW.write(Yaw);
  Serial.print("Throttle:\t");Serial.print(Throttle);
  Serial.print("\t Yaw:\t");Serial.println(Yaw);
}
void handleStick2() {
  String tmp=server.arg("PITCH");int temp=tmp.toInt();
  int Pitch = map(temp,-100,100,0,180);
  tmp=server.arg("ROLL");temp=tmp.toInt();
  int Roll = map(temp,-100,100,0,180);  
  server.send(200, "text/plane", "");
  if(Pitch>=0&&Pitch<=180)servo_PITCH.write(Pitch);
  if(Roll>=0&&Roll<=180)servo_ROLL.write(Roll);
 Serial.print("Pitch:\t");Serial.print(Pitch);
  Serial.print("\t Roll:\t");Serial.println(Roll);

}
void NotC(){
  if(Throttle>0){Throttle>4?(Throttle=Throttle-4):(Throttle=Throttle-1);
  servo_THROTTLE.write(Throttle);
  servo_YAW.write(90);
  servo_PITCH.write(90); 
  servo_ROLL.write(90);Serial.print(Throttle);
  delay(1000); server.handleClient();
  } else if (Throttle<=0) server.handleClient();
}



void setup() {
  Serial.begin(115200);
  delay(500);
  servo_THROTTLE.attach(2,1000,2000,0);
  servo_YAW.attach(12,1000,2000,0);
  servo_PITCH.attach(13,1000,2000,0); 
  servo_ROLL.attach(15,1000,2000,0);
  pinMode(D1, OUTPUT);
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid,password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/Stick1", handleStick1);
  server.on("/Stick2", handleStick2); 
  server.begin();
  Serial.println("HTTP server started");

}
void loop() {  if(WiFi.softAPgetStationNum()>0)server.handleClient();else NotC();} 