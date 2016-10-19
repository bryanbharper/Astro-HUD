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
    /*** Properties ***/
      // Sensor Specific
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

      // Front End Specific
        String display_name;
        float display_value;
        bool display_me;
        /* Overwrite variables:
            Depending on the hardware, the display's refresh rate can be rather
            slow (just a few fps). To avoid a full screen refresh, one can
            simply overwrite the exact pixels previously dislayed. The variables
            below store the necessary information for overwritting the previously
            data displayed for a given sensor. */
            unsigned short int last_display_x;
            unsigned short int last_display_y;
            unsigned short int last_display_value_x;
            unsigned short int last_display_value_y;
            float last_display_value;


    /*** Methods ***/
      void update();
      void check_thresh();
      void convert();
      void calc_priority();
      
};

#endif
