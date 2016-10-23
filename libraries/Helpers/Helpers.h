/*
  Helpers.h
  ....
*/
#ifndef Helpers_h
#define Helpers_h

#include "Sensor.h"

/****************************************************************************************//**
 * \brief Used to convert rgb color codes to 16-bit values.
 *
 * Some display drivers use 16-bit values to represent colors. However, rgb is often a
 * more intuitive and easily manuipulated representation. This functions fascilitates the
 * conversion.
 *
 * The `r` parameter takes values from 0-31.
 * The `g` parameter takes values from 0-63.
 * The `b` parameter takes values from 0-31.
 *
 * For information 16-bit color representation,
 * see [here](https://en.wikipedia.org/wiki/High_color).
 *******************************************************************************************/
unsigned short int rgbTo16(unsigned short int r, unsigned short int g, unsigned short int b);

/****************************************************************************************//**
 * \brief Sorts an array of Sensors by priority.
 *
 * The sensors are arranged from high priority to low priority (i.e., the senors in the 0th
 * position of the array will be of the highest priority).
 *
 * Given that only a small number of sensors are expected to be used by the HUD system (maybe a
 * dozen, at most) a simiple bubble-sort algorithm  is used as performance differences with such
 * a small number of elements will be negligible.
 *******************************************************************************************/
void priority_sort(Sensor a[], unsigned short int size);

#endif
