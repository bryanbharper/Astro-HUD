/*
  Clock.cpp - Library for
  ...
*/

#include "Clock.h"

//Constructor for processor speed in MHz
Clock::Clock(int PC_speed)
{
  speed = PC_speed;
//  hour=0;
//  min=0;
  sec=0;
  wait=0;
}

//function not needed if delay works
//delay(speed*10^6);
//DC comic flash not blinking
void Clock::flash()
{
  while(wait != (speed*10^6))
  {
    wait++;
  }
}

void Clock::constraints()
{
  if(sec > 59)
  {
//    min += 1;
    sec = 0;
  }
/*  if (min > 59)
  {
    hour += 1;
    min = 0;
  }*/
}

void Clock::update()
{
  flash();//or delay(speed*10^6);
  sec++;
  wait=0;//not needed if delay
  constraints();
}
