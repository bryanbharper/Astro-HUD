/*
  Sensor.cpp - Library for
  ...
*/

#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int pin, int hi_thresh, int lo_thresh, double conv_coef, double conv_offset)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

void Sensor::update()
{
  
}
