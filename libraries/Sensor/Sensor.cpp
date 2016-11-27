#include "Sensor.h"


// Constructor
Sensor::Sensor(String name, int Pin, float Hi_thresh, float Lo_thresh, float Hi_bound,
               float Lo_bound,  float Conv_coef, float Conv_offset)
{
  /* Sensor Specific */
    pin = Pin;
    pinMode(pin, INPUT);
    hi_thresh = Hi_thresh;
    lo_thresh = Lo_thresh;
    hi_bound = Hi_bound;
    lo_bound = Lo_bound;
    mid_hi = Hi_thresh - (Hi_thresh/4);
    mid_lo = Lo_thresh + (Lo_thresh/4);
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

Sensor::Sensor(String name, int Pin, float Hi_thresh, float Lo_thresh, float Hi_bound,
               float Lo_bound,  float Conv_coef, float Conv_offset, float Priority_offset)
{
  /* Sensor Specific */
    pin = Pin;
    pinMode(pin, INPUT);
    hi_thresh = Hi_thresh;
    lo_thresh = Lo_thresh;
    hi_bound = Hi_bound;
    lo_bound = Lo_bound;
    mid_hi = Hi_thresh - (Hi_thresh/4);
    mid_lo = Lo_thresh + (Lo_thresh/4);
    conv_coef = Conv_coef;
    conv_offset = Conv_offset;
    priority = 0;
    priority_offset = Priority_offset;

  /* Front End Specific */
    display_name = name;
    display_me = false;
    last_display_x = 0;
    last_display_y = 0;
    last_display_value_x = 0;
    last_display_value_y = 0;
    last_display_value = 0;

}

Sensor::Sensor()
{}

void Sensor::convert()
{
  // Convert to relevnt units. Limit to two decimal places (to limit oled flashing).
  display_value = roundf( conv_coef * sensor_read + conv_offset);
}

void Sensor::check_thresh()
{
  if( ( display_value <= mid_lo) || ( display_value >= mid_hi) )
  {
    display_me = true;
  }  else {
    display_me = false;
  }

}

void Sensor::update()
{
  sensor_read = analogRead(pin);
  convert();
  check_thresh();
  calc_priority();
  if ( display_me )
  {
    if( (display_value < hi_thresh) || (display_value > lo_thresh ) )
    {
      millis();
      millis();
      millis();
      millis();
      millis();
      display_me = false;
    }
  }
}

void Sensor::calc_priority()
{
  if( (display_value < mid_hi) && ( display_value > mid_lo) ){
    priority = priority_offset;
  }
  if( display_value > hi_thresh){
    priority = abs( display_value - hi_thresh) / abs(hi_bound - hi_thresh) + priority_offset;
    /*
        r_color = 31;
        g_color = 63*(1-priority);
        b_color = 31*(1-priority);
        ///< from white to red
    */
        r_color = 31;
        g_color = 63*(1-priority);
        b_color = 0;
        ///< from yellow to red. aka different shades of orange
  }
  else if ( display_value < lo_thresh)
  {
    priority = abs(lo_thresh - display_value) / abs(lo_thresh - lo_bound) + priority_offset;
/*
    r_color = 31;
    g_color = 63*(1-priority);
    b_color = 31*(1-priority);
    ///< from white to red
*/
    r_color = 31;
    g_color = 63*(1-priority);
    b_color = 0;
    ///< from yellow to red. aka different shades of orange
  }
  else if ( display_value > mid_hi)
  {
    priority = abs( display_value - mid_hi) / abs(hi_bound - mid_hi) + priority_offset;
    r_color = 31;
    g_color = 63;
    b_color = 31*(1-priority);
    ///< from white to yellow
  }
  else ( display_value < mid_lo)
  {
    priority = abs(mid_lo - display_value) / abs(mid_lo - lo_bound) + priority_offset;
    r_color = 31;
    g_color = 63;
    b_color = 31*(1-priority);
    ///< from white to yellow
  }
}
