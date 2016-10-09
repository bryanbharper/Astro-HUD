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
  Sensor(int Pin, float Hi_thresh, float Lo_thresh, float Conv_coef, float Conv_offset);
  Sensor(String name, int Pin, float Hi_thresh, float Lo_thresh, float Conv_coef, float Conv_offset);
    // Properties
    bool display_me;
    float hi_thresh;
    float lo_thresh;
    float conv_coef;
    float conv_offset;
    unsigned short int pin;
    unsigned short int sensor_read;
    float display_value;
    String display_name;
    // Methods
    void update();
    void check_thresh();
    void convert();

  private:
    // Tumble weed
};

#endif
