/*
#include <Servo.h>
Servo myservo; 
int val=0;   
void setup() {
  Serial.begin(9600);  
pinMode(LED_BUILTIN, OUTPUT);
 myservo.attach(0,1000,2000,0); 
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
} 

*/
  
// ESc Control and Work
#include <Servo.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>


  ESP8266WiFiMulti WiFiMulti;
  Servo myservo;  // create servo object to control a servo
  int val=0;    // variable to read the value from the analog pin
  void setup() {
   
      myservo.attach(0,1000,2000,0); 
	myservo.write(180);
 	delay(5000);
  	myservo.write(0);
  	delay(2000);
  	myservo.write(10);
	delay(5000);
Serial.begin(9600); 

pinMode(LED_BUILTIN, OUTPUT);  
  digitalWrite(LED_BUILTIN, LOW);       
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("realme 9 Pro+", "111111111");
  Serial.println("setup() done connecting to ssid");
  digitalWrite(LED_BUILTIN, HIGH); 

}

  void loop() {
  
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) { 
    std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
   client->setInsecure();
    HTTPClient https;
    if (https.begin(*client, "https://prathameshbhagat.000webhostapp.com/m/m.php")) {  
      // start connection and send HTTP header
      int httpCode = https.GET();
      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          
          int l =payload.length();
          payload.remove(l-1);
          Serial.println(payload+":");
            int outcome =payload.toInt();
            if(outcome<=180&&outcome>=0)
            val=outcome;
        
        }
      } else {
          
      digitalWrite(LED_BUILTIN, LOW); delay(1000);digitalWrite(LED_BUILTIN, HIGH);
      Serial.printf("[HTTPS] GET... failed, ");//error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
  digitalWrite(LED_BUILTIN, LOW); delay(1000);digitalWrite(LED_BUILTIN, HIGH);
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }
if(val<=180&&val>=0)myservo.write(val);
 
 }


