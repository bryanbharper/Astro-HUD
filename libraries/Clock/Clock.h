/*
  Clock.h
  ....
*/
#ifndef Clock_h
#define Clock_h

#include <Arduino.h>
#include <string.h>
#include <math.h>

/****************************************************************************************//**
* \brief The Clock object calculates and stores the mission time.
*
* A hardware clock is used to create an interupt once a second to increment
* the sec property of the Clock object. Based on the sec value, the min and hour properties
* are updated.
 *******************************************************************************************/
class Clock
{
  public:

  /********************************************//**
  * \brief Clock constructor.
  ***********************************************/
  Clock();
  //Properties
  int hour; ///< Stores hour value of mission clock.

  int min;  ///< Stores minute value of mission clock.

  int sec;   ///< Stores second value of mission clock.

  unsigned long prevMillis;

  unsigned long currentMillis;

  unsigned long interval; ///< Used for hardware interupt. Value depends on hardware clock speed.

  //Methods
  /********************************************//**
  * The update method is called by the hardware
  * interupt handler. It increments sec and calculates
  * constraints.
  ***********************************************/
  void update();

  /********************************************//**
  * The constraints method checks whether the
  * sec or min property is equal to 60. If so,
  * the property is set to 0, and the min or
  * hour property is incremented appropriately.
  ***********************************************/
  void constraints();

}
