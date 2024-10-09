// Build a circuit that lights an LED when it is sufficiently dark in a room.
// Demonstrate the circuit by covering the photoresistor to simulate darkness.

#include <Arduino.h>

#define LED_PIN 13
#define PHOTO_PIN A0
#define THRESHOLD 100

void setup()
{
  Serial.begin(9600);
  pinMode(PHOTO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int photo = analogRead(PHOTO_PIN);
  // Serial.println(photo);

  if (photo < THRESHOLD)
  {
    Serial.println("Lights on");
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {

    Serial.println("Lights off");
    digitalWrite(LED_PIN, LOW);
  }
}
