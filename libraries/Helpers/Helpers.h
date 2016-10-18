/*
  Helpers.h
  ....
*/
#ifndef Helpers_h
#define Helpers_h

#include "Sensor.h"

/*****************************************************************************
  rgbTo16(unsigned short, unsigned short, unsigned short)

  Description: Converts the familiar rgb color format into 16-bit color values.
    0 <= r <= 31
    0 <= g <= 63
    0 <= b <= 31
*****************************************************************************/
unsigned short int rgbTo16(unsigned short int r, unsigned short int g, unsigned short int b);

/*****************************************************************************
  void priority_sort(Sensor * array[], unsigned short int size)

  Description: Sorts sensors by priority
*****************************************************************************/
void priority_sort(Sensor a[], unsigned short int size);

#endif
