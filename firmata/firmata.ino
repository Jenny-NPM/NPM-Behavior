#include <Firmata.h>

byte analogPin;

void analogWriteCallback(byte pin, int value)
{
  pinMode(pin, OUTPUT);
  analogWrite(pin, value);
}

void setup()
{
  Firmata.setFirmwareVersion(FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
  Firmata.begin();
}

void loop()
{
  while (Firmata.available()) {
    Firmata.processInput();
  }
 
    Firmata.sendAnalog(0, (analogRead(0)*(5000/1024)));
    delay(1);
   
  }

