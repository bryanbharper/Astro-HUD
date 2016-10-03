/*
  Sensor.cpp - Library for
  ...
*/

// #include "Arduino.h"
#include "Sensor.h"

// Constructor without Name
Sensor::Sensor(int Pin, float Hi_thresh, float Lo_thresh, float Conv_coef, float Conv_offset)
{
  pinMode(pin, INPUT);
  pin = Pin;
  hi_thresh = Hi_thresh;
  lo_thresh = Lo_thresh;
  conv_coef = Conv_coef;
  display_me = false;
  display_name = "Unnamed";
}

// Constructor with Name
Sensor::Sensor(String name, int Pin, float Hi_thresh, float Lo_thresh, float Conv_coef, float Conv_offset)
{
  pinMode(pin, INPUT);
  pin = Pin;
  hi_thresh = Hi_thresh;
  lo_thresh = Lo_thresh;
  conv_coef = Conv_coef;
  display_me = false;
  display_name = name;
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
