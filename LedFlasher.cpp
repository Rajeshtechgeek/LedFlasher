/*
  LedFlasher.cpp - Library for flashing LED.
  Created by Rajesh K, September 12, 2020.
  Released into the public domain.
*/
#include "LedFlasher.h"
#include "Arduino.h"

LedFlasher::LedFlasher(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

LedFlasher::LedFlasher(int pin, int steps, int maxDuration)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _steps = steps;
  _maxDuration = maxDuration;
}

void LedFlasher::blinkActiveLow(int n, int delay1, int delay2)
{
  digitalWrite(_pin, LOW);
  for (int i = 1; i < n; i++)
  {
    delay(delay1);
    digitalWrite(_pin, HIGH);
    delay(delay1);
    digitalWrite(_pin, LOW);
  }
  delay(delay1);
  digitalWrite(_pin, HIGH);
  delay(delay2);
}

void LedFlasher::blinkActiveHigh(int n, int delay1, int delay2)
{
  digitalWrite(_pin, HIGH);
  for (int i = 1; i < n; i++)
  {
    delay(delay1);
    digitalWrite(_pin, LOW);
    delay(delay1);
    digitalWrite(_pin, HIGH);
  }
  delay(delay1);
  digitalWrite(_pin, LOW);
  delay(delay2);
}

void LedFlasher::acceleration1()
{
  digitalWrite(_pin, HIGH);
  delay(_blinkDuration);
  digitalWrite(_pin, LOW);
  delay(_blinkDuration);

  // change the blinkDuration for next time through the loop:
  _blinkDuration = _blinkDuration - _singleStepValue;

  // reset the speed of the blinking at the end:
  if (_blinkDuration < _singleStepValue || _blinkDuration >= _maxDuration)
  {
    //reset blink duration
    _blinkDuration = _maxDuration;
  }
}

void LedFlasher::acceleration2()
{
  digitalWrite(_pin, HIGH);
  delay(_blinkDuration);
  digitalWrite(_pin, LOW);
  delay(_blinkDuration);

  // change the blinkDuration for next time through the loop:
  _blinkDuration = _blinkDuration - _singleStepValue;

  // reverse the speed of the blinking at the end:
  if (_blinkDuration < _singleStepValue || _blinkDuration >= _maxDuration)
  {
    //change the sign of value
    _singleStepValue = -_singleStepValue;
  }
}
