// Write a program that allows the user to control the LED connected to pin 13
// of the Arduino. 

// When the program started, the LED should be off. The user should open the serial
// monitor to communicate with the Arduino. If the user sends the character '1'
// through the serial monitor then the LED should turn on. If the user sends the
// character '0' through the serial monitor then the LED should turn off.

#include <Arduino.h>

#define LED_BUILTIN 13
char control;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // frequency
}

void loop()
{
  if (Serial.available() > 0) {
    control = Serial.read();
    switch (control) {
      case '0':
        digitalWrite(LED_BUILTIN, LOW);
        break;
      case '1':
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    }
  }
}
