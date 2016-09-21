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
    Sensor(int pin, int hi_thresh, int lo_thresh, double conv_coef, double conv_offset);
    void update();
  private:
    int _pin;
};

#endif
