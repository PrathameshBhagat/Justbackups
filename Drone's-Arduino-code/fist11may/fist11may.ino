/*
#include <Servo.h>
Servo myservo;
int val=0;
void setup() {
Serial.begin(9600);  
pinMode(LED_BUILTIN, OUTPUT);
//myservo.attach(2,1000,2000,0);
myservo.attach(2,500,2400);
myservo.write(180);
delay(5000);
myservo.write(0);
delay(2000);
myservo.write(10);
}
void loop() {
 if(Serial.available())
    {  val = Serial.parseInt(); ///if(val>=0)if(val<=180)  
      myservo.write(val); 
 Serial.print(val);  Serial.print("\n"); 
    }
 // delay(15);
} */
 #include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Servo.h>
ESP8266WiFiMulti WiFiMulti;
Servo servo1,servo2,servo3,servo4; 
String payload;
int THROTTLE=0,YAW=0,PITCH=0,ROLL=0;bool chk = false;
void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  pinMode(LED_BUILTIN, OUTPUT); 
  servo1.attach(2,1000,2000,0); 
  //servo1.attach(2,500,2400,0); 
  servo2.attach(12,1000,2000,0); 
  servo3.attach(13,1000,2000,0);
  servo4.attach(15,1000,2000,0);
  digitalWrite(LED_BUILTIN, HIGH); 
  Serial.println("connecting to WiFi"); 
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("realme 9 Pro+", "111111111");
  while(true)if ((WiFiMulti.run() == WL_CONNECTED)) break;  
  Serial.println("setup() done connecting to ssid");digitalWrite(LED_BUILTIN, LOW);   
}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;
    if (http.begin(client, "http://prathameshbhagat.000webhostapp.com/m/m.php")) { 
      int httpCode = http.GET();
      if (httpCode > 0) {
        Serial.printf("\n-> GET... code: %d ::", httpCode);
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          payload = http.getString();chk=true;
        }
      } else{Serial.printf("-> GET... failed, error: %s\n", http.errorToString(httpCode).c_str());er(); }
      http.end();
    } else {Serial.println("=> Unable to connect to Server");er(); }
    if(chk){
          int l =payload.length();
          int A[4];
          payload.remove(l-2);
          convert(payload,A);
          A[0]=map(A[0],-100,100,0,180);
          A[1]=map(A[1],-100,100,0,180);
          A[2]=map(A[2],-100,100,0,180);
          A[3]=map(A[3],-100,100,0,180);
          Serial.print("PIITCH: ");Serial.print(A[0]);
          Serial.print(" ROLL: ");Serial.print(A[1]);
          Serial.print(" THROTTLE: ");Serial.print(A[2]);
          Serial.print(" YAW: ");Serial.print(A[3]);
          if(A[0]<=180&&A[0]>=0)servo1.write(A[2]);
          if(A[1]<=180&&A[1]>=0)servo2.write(A[3]);
          if(A[2]<=180&&A[2]>=0)servo3.write(A[0]);
          if(A[3]<=180&&A[3]>=0)servo4.write(A[1]);
          chk=false;
    }
  }
}
void er(){digitalWrite(LED_BUILTIN, HIGH); delay(1000);digitalWrite(LED_BUILTIN, LOW); }
void convert(String S,int Z[]){
  String temp="";int i=S.lastIndexOf(" ");
  for(int a=0;a<4;a++){
    temp=S.substring(i,S.length());
    Z[a]=temp.toInt();S.remove(i);
    if(a==2)i=0;else i=S.lastIndexOf(" ");
  }
}
