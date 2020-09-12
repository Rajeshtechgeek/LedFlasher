/**
 * Blink led mutiple times
 *
 */
#include "Arduino.h"
#include "LedFlasher.h"

LedFlasher ledFlasher(LED_BUILTIN);

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // ledFlasher.blinkActiveLow(3, 50, 400);
  // ledFlasher.blinkActiveHigh(3, 50, 400);
  ledFlasher.acceleration1();
  // ledFlasher.acceleration2();
}