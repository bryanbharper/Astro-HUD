/*
  Sensor.h
  ....
*/
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class Sensor
{
  public:
   Sensor(int Pin, float Hi_thresh, float Lo_thresh, float Conv_coef, float Conv_offset);
    void update();
    void check_thresh();
    void convert();
    bool display_me;
    float hi_thresh;
    float lo_thresh;
    float conv_coef;
    float conv_offset;
    int pin;
    int sensor_read;
    float display_value;

  private:
    // Tumble weed
};

#endif
