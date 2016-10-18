/*
  Sensor.h
  ....
*/
#ifndef Sensor_h
#define Sensor_h

#include <Arduino.h>
#include <string.h>
#include <math.h>

class Sensor
{
  public:
    Sensor();
    Sensor(String name, int Pin, float Hi_thresh, float Lo_thresh, float Hi_bound, float Lo_bound, float Conv_coef, float Conv_offset);
    // Properties
    bool display_me;
    int display_value_x;
    float hi_thresh;
    float lo_thresh;
    float hi_bound;
    float lo_bound;
    float priority;
    float priority_offset;
    float conv_coef;
    float conv_offset;
    unsigned short int pin;
    unsigned short int sensor_read;
    float display_value;
    float last_display_value;
    String display_name;
    // Methods
    void update();
    void check_thresh();
    void convert();
    void calc_priority();
  private:
    // Tumble weed
};

#endif
