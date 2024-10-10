// Write a sketch that allows a user access data in EEPROM using the serial monitor.
// In the serial monitor the user should be able to type one of two commands: "read"
// and "write. "Read" takes one argument, an EEPROM address. "Write" takes two arguments,
// an EEPROM address and a value.
//
// For example, if the user types "read 3" then the contents of EEPROM address
// 3 should be printed to the serial monitor. If the user types "write 3 10" then
// the value 10 should be written into address 3 of the EEPROM.

#include <Arduino.h>
#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);
  Serial.print("EEPROM length: ");
  Serial.println(EEPROM.length());
}

void loop()
{
  if (!Serial.available())
  {
    return;
  }

  String cmd = Serial.readStringUntil(' ');
  int addr;
  uint8_t data;

  if (cmd == "read")
  {
    addr = Serial.readStringUntil(' ').toInt();
    data = EEPROM.read(addr);
    Serial.println(data, DEC);
  }
  else if (cmd.startsWith("write"))
  {
    addr = Serial.readStringUntil(' ').toInt();
    data = Serial.readStringUntil(' ').toInt();
    EEPROM.write(addr, data);
  }
  else
  {
    Serial.write("Unrecognized command.\n");
  }
}
