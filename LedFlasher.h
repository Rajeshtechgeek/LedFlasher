/*
  LedFlasher.h - Library for flashing LED.
  Created by Rajesh K, September 12, 2020.
  Released into the public domain.
*/

#ifndef LedFlasher_h
#define LedFlasher_h

#include "Arduino.h"

class LedFlasher
{
public:
    LedFlasher(int pin);
    LedFlasher(int pin, int steps, int maxDuration);
    void blinkActiveLow(int n, int delay1, int delay2);
    void blinkActiveHigh(int n, int delay1, int delay2);
    void acceleration1();
    void acceleration2();

private:
    int _pin;
    int _maxDuration = 200;
    int _blinkDuration = _maxDuration;
    int _steps = 20;
    int _singleStepValue = _blinkDuration / _steps;
};

#endif