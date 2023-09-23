#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h> 
#include "PageIndex.h"
const char* ssid = "ESPServo";  // your SSID
const char* password = "11111111"; //WIFI Password 
int Throttle=0;
Servo servo_THROTTLE,servo_YAW,servo_PITCH,servo_ROLL,servo_DROP; 
ESP8266WebServer server(80); 
void handleRoot() {
  String s = MAIN_page; 
  server.send(200, "text/html", s); 
}
void handleDROP() {
  String s = SUPPORT_page; 
  server.send(200, "text/html", s); 
}

void handleStick1() {
  Throttle = map(server.arg("THROTTLE").toInt(),-100,100,0,180);
  int Yaw = map(server.arg("YAW").toInt(),-100,100,0,180);
  server.send(200, "text/plane", "");
  if(Throttle>=0&&Throttle<=180)servo_THROTTLE.write(Throttle);  
  if(Yaw>=0&&Yaw<=180)servo_YAW.write(Yaw);
  Serial.print("Throttle:\t");Serial.print(Throttle);
  Serial.print("\t Yaw:\t");Serial.println(Yaw);
}
void handleStick2() {
  int Pitch = map(server.arg("PITCH").toInt(),-100,100,0,180);
  int Roll  = map(server.arg("ROLL").toInt(),-100,100,0,180);  
  server.send(200, "text/plane", "");
  if(Pitch>=0&&Pitch<=180)servo_PITCH.write(Pitch);
  if(Roll>=0&&Roll<=180)servo_ROLL.write(Roll);
  Serial.print("Pitch:\t");Serial.print(Pitch);
  Serial.print("\t Roll:\t");Serial.println(Roll);

}
void handleDistance(){
  if(!(server.arg("analog")==""))   
    analogWrite(4,server.arg("analog").toInt());  
  else
   servo_DROP.write(server.arg("pwm").toInt());
  server.send(200, "text/plane", "");
}
void NotC(){
  if(Throttle>0){Throttle>4?(Throttle=Throttle-4):(Throttle=Throttle-1);
  servo_THROTTLE.write(Throttle);
  servo_YAW.write(90);
  servo_PITCH.write(90); 
  servo_ROLL.write(90);Serial.print(Throttle);
  delay(1500); server.handleClient();
  } else if (Throttle<=0) server.handleClient();
}

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  servo_DROP.attach(5,500,2400,0);
  servo_THROTTLE.attach(2,1000,2000,0);
  servo_YAW.attach(12,1000,2000,0);
  servo_PITCH.attach(13,1000,2000,0); 
  servo_ROLL.attach(15,1000,2000,0);
  pinMode(4, OUTPUT);
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid,password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/Stick1", handleStick1);
  server.on("/Stick2", handleStick2);
  server.on("/DROP", handleDROP);
  server.on("/distance",handleDistance);

  server.begin();
  Serial.println("HTTP server started");

}
void loop() {  if(WiFi.softAPgetStationNum()>0)server.handleClient();else NotC();}
