#ifndef Sensor_h
#define Sensor_h

#include <Arduino.h>
#include <string.h>
#include <math.h>

/****************************************************************************************//**
* \brief Sensor objects store information & provide methods for a given hardware sensor.
*
* For each hardware sensor connected to the HUD system a Sensor object must be instantiated.
* This object is used to handle all actions pertaining to the hardware sensor.
*
* From the point of view of the microcontroller running the HUD system code, a hardware sensor
* is simply a voltage on one of the GPIO pins. For the voltage to be converted into meaningful
* data, it is necessary to keep track of information about the hardware sensor and tie that
* information to the value read on the given GPIO pin. For example, in order for a voltage to
* represent a given physical parameter, it is necessary to know the conversion formula from volts
* to the desired physical units.
*
* An instantiated Sensor object keeps track of all necessary sensor properties, such as the
* sensor's name, units, conersion factors, current and previous values, etc.. It also has methods
* for performing various sensor related actions, such as reading a voltage off of a pin, converting
* that value into the specified units, and updating the sensors priority based on external
* information.
*
* There are also various properties and operations specific to the HUD system that need to be
* tracked in order to make decisions about how and when to display  information
* on the HUD (see calc_priority, hi_thresh, lo_thresh, and priority). The Sensor object is also
* used to define and utilize these HUD specific members.
*
 *******************************************************************************************/
class Sensor
{
  public:
    /********************************************//**
    *  \brief Constructor for Sensor object.
    *
    * The parameters of the Sensor constructor include
    * of all the user-specified (via config file)
    * hardware sensor properties which cannot be
    * determined internally. These values are
    * assigned upon instantiation to the
    * corresponding Sensor properties. Any other
    * properties are assigned default values
    * (generally zero).
    *
    * _Note:_ By convention, parameter names are capitalized, and the corresponding Sensor property
    * goes by the same name, except in all lower-case.
    ***********************************************/
    Sensor(String name, int Pin, float Hi_thresh, float Lo_thresh, float Hi_bound, float Lo_bound,
           float Conv_coef, float Conv_offset);

    Sensor();

      String display_name;  ///< The name of the sensor (used on the HUD).

      unsigned short int pin; ///< A numeric value that represents the pin on the microcontroller
                              ///< which the sensor is connected too. This value will be defined
                              ///< by microcontroller manufacturer.

      unsigned short int sensor_read; ///< The raw value read off the assigned hardware pin.

      float display_value;  ///< The sensor value converted into approriated units.

      float hi_bound;   ///< This value specifies the highest value (in the sensor's units,
                        ///< not volts) the hardware sensor is capable of reaching.

      float lo_bound;   ///< This value specifies the lowest value (in the sensor's units,
                        ///< not volts) the hardware sensor is capable of reaching.

      float hi_thresh;  ///< A sensor value (in the sensor's units, not volts) above this will set
                        ///< display_me to _True_. If the sensor value in between hi_thres and
                        ///< lo_thresh, display_me wil lbe set to _False_.

      float lo_thresh;  ///< A sensor value (in the sensor's units, not volts) below this will set
                        ///< display_me to _True_. If the sensor value in between hi_thres and
                        ///< lo_thresh, display_me wil lbe set to _False_.

      float conv_coef;  ///< The relationship between the voltage produced by the hardware sensor
                        ///< and the physical parameter represented is assumed to be linear. This
                        ///< is a good approximation in most practical applications. conv_coef is
                        //< the slope of the linear approximation.

      float conv_offset;  ///< The relationship between the voltage produced by the hardware
                          ///< sensor and the physical parameter represented is assumed to be
                          ///< linear. This is a good approximation in most practical
                          ///< applications. conv_offset is the offset of the linear
                          ///< approximation.

      float priority;     ///< Each sensor is dynamically assigned a priority score for decissions
                          ///< regaurding when and how to display information.

      float priority_offset;  ///< Set to zero by default, this property is used to give a sensor
                              ///< an _intrinsic_ priorrity. All sensors are genearlly assumed to
                              ///< have the same _intrinsic_ priority, and so this is set to zero
                              ///< by default. However, this property can used to "boost" or
                              ///< "subdue" a sensor's priority relative to others.

      bool display_me;  ///< A bollean used to determine whether or not a sensor should be
                        ///< displayed at any given moment. Sensor values are not always on
                        ///< displayed in order to avoid information fatigue.

      unsigned short int last_display_x;  ///< Tracks x-coordinate of the senor's name on HUD.
                                          ///< Used by front end to clear OLED.

      unsigned short int last_display_y;  ///< Tracks y-coordinate of the senor's name on HUD.
                                          ///< Used by front end to clear OLED.

      unsigned short int last_display_value_x;  ///< Tracks x-coordinate of display_value on HUD.
                                                ///< Used by front end to clear OLED.

      unsigned short int last_display_value_y;  ///< Tracks y-coordinate of display_value on HUD.
                                                ///< Used by front end to clear OLED.

      float last_display_value; ///< Tracks sensor's display_value. Used by front end to clear OLED.


    /********************************************//**
    * \brief Dynamically updates all sensor properties.
    *
    * Calling update will read the assigned pin value,
    * then call convert, check_thresh, and calc_priority.
    ***********************************************/
    void update();

    /********************************************//**
    * Calling check_thresh will determine whether
    * the current display_value is outside hi_thresh
    * and lo_thresh. If it is outside the threshold,
    * display_me is set to _True_. Otherwise it is set
    * to _False_.
    ***********************************************/
    void check_thresh();

    /********************************************//**
    * Calling convert will calculate and update
    * the sensor value in its proper units. The
    * formula is:
    *
    *     display_value = conv_coef * sensor_read + conv_offset
    ***********************************************/
    void convert();

    /********************************************//**
    * Calling calc_priority up calculate priority.
    * The formula is seen here:
    *
    * ![Priority Formula](/home/bryan/GIT_projects/Astro-HUD/documentation/Priority_Formula.png)
    ***********************************************/
    void calc_priority();

};

#endif
