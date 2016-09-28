/*
  Sensor.cpp - Library for
  ...
*/

#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int Pin, int Hi_thresh, int Lo_thresh, double Conv_coef, double Conv_offset)
{
  pinMode(pin, INPUT);
  pin = Pin;
  hi_thresh = Hi_thresh;
  lo_thresh = Lo_thresh;
  conv_coef = Conv_coef;
  display_me = false;
}

void Sensor::convert()
{
  display_value = conv_coef * sensor_read + conv_offset;
}

void Sensor::check_thresh()
{
  if( ( display_value <= lo_thresh ) || ( display_value >= hi_thresh ) )
  {
    display_me = true;
  } else {
    display_me = false;
  }
}

void Sensor::update()
{
  sensor_read = analogRead(pin);
  convert();
  check_thresh();
}
