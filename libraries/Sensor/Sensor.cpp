/*
  Sensor.cpp - Library for
  ...
*/

// #include "Arduino.h"
#include "Sensor.h"


// Constructors
Sensor::Sensor(){
  /* Sensor Specific */
    pin = A0;
    pinMode(pin, INPUT);
    hi_bound = 1023;
    lo_bound = 0;
    hi_thresh = hi_bound;
    lo_thresh = lo_bound;
    priority = 0;
    priority_offset = 0;
    conv_coef = 1;
    conv_offset = 0;

  /* Front End Specific */
    display_name = name;
    display_me = false;
    last_display_x = 0;
    last_display_y = 0;
    last_display_value_x = 0;
    last_display_value_y = 0;
    last_display_value = 0;
}

Sensor::Sensor(String name, int Pin, float Hi_thresh, float Lo_thresh, float Hi_bound, float Lo_bound,  float Conv_coef, float Conv_offset)
{
  /* Sensor Specific */
    pin = Pin;
    pinMode(pin, INPUT);
    hi_thresh = Hi_thresh;
    lo_thresh = Lo_thresh;
    hi_bound = Hi_bound;
    lo_bound = Lo_bound;
    conv_coef = Conv_coef;
    conv_offset = Conv_offset;
    priority = 0;
    priority_offset = 0;


  /* Front End Specific */
    display_name = name;
    display_me = false;
    last_display_x = 0;
    last_display_y = 0;
    last_display_value_x = 0;
    last_display_value_y = 0;
    last_display_value = 0;

}

void Sensor::convert()
{
  // Convert to relevnt units. Limit to two decimal places (to limit oled flashing).
  display_value = roundf( conv_coef * sensor_read + conv_offset);
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
  calc_priority();
}

void Sensor::calc_priority()
{
  if( (display_value < hi_thresh) && ( display_value > lo_thresh) ){
    priority = priority_offset;
  }
  else if( display_value > hi_thresh){
    priority = abs( display_value - hi_thresh) / abs(hi_bound - hi_thresh) + priority_offset;
  }
  else{
    priority = abs(lo_thresh - display_value) / abs(lo_thresh - hi_bound) + priority_offset;
  }
}
