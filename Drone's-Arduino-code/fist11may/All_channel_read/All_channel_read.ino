/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/
 // variable to store the value coming from the sensor
#include <Arduino.h>
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(6, INPUT);
  pinMode(9,INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);Serial.begin(9600);
}

void loop() {
  double THROTTLE=pulseIn(6,HIGH);
  double YAW=pulseIn(9,HIGH);
  double PITCH=pulseIn(10,HIGH);
  double ROLL=pulseIn(11,HIGH);
  Serial.print("\nThrottle:");
  Serial.print(THROTTLE);
  Serial.print(" Yaw:");
  Serial.print(YAW);
  Serial.print(" Pitch:");
  Serial.print(PITCH);
  Serial.print(" ROLL:");
  Serial.print(ROLL);delay(1000);

}
