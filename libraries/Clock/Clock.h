/*
  Clock.h
  ....
*/
#ifndef Clock_h
#define Clock_h

#include <Arduino.h>
#include <string.h>
#include <math.h>

class Clock
{
  public:
  Clock(int PC_speed);//MHz_PC_speed(int speed);
  //Properties
  int speed;
  //int hour;
  //int min;
  int sec;
  int wait;
  //Methods
  void flash();//DC comic flash not blinking
  void update();
  void constraints();


}
