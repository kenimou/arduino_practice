// Write a program that causes the built-in LED connected to pin 13 on the Arduino
// to blink, alternating between fast blinks and slow blinks.

// The LED should blink 5 times quickly and then it should blink 5 more times slowly.
// When blinking quickly, the LED should have a 1 second period, so it should be high
// for 0.5 seconds and low for 0.5 seconds. When blinking slowly, the LED should have
// a 4 second period, so it should be high for 2 seconds and low for 2 seconds. The
// LED should continue to blink in this alternating fashion for as long as the Arduino
// receives power.

#include <Arduino.h>

#define LED_BUILTIN 13
#define FAST_INTERVAL 500
#define SLOW_INTERVAL 2000

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(FAST_INTERVAL);
    digitalWrite(LED_BUILTIN, LOW);
    delay(FAST_INTERVAL);
  }
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(SLOW_INTERVAL);
    digitalWrite(LED_BUILTIN, LOW);
    delay(SLOW_INTERVAL);
  }
}
