#include "Helpers.h"

/*****************************************************************************
  rgbTo16(unsigned short int r, unsigned short int g, unsigned short int b)

  Description: Converts the familiar rgb color format into 16-bit color values.
    0 <= r <= 31
    0 <= g <= 63
    0 <= b <= 31
*****************************************************************************/
unsigned short int rgbTo16(unsigned short int r, unsigned short int g, unsigned short int b)
{
  // Bound to legal values
  if(r < 0)
  {
    r = 0;
  }
  if(r > 31)
  {
    r = 31;
  }
  if(g < 0)
  {
    g = 0;
  }
  if(g > 63)
  {
    r = 63;
  }
  if(b < 0)
  {
    b = 0;
  }
  if(b > 31)
  {
    b = 31;
  }

  // Return 16-bit color value
  return (r << 11 ) + (g << 5) + b;
}


/*****************************************************************************
  void priority_sort(Sensor * array[], unsigned short int size)

  Description: Sorts array sensors by priority
*****************************************************************************/
void priority_sort(Sensor a[], unsigned short int size)
{
  int i, j, flag = 1;    // Initialize flag to 1
  Sensor temp;
  for(i = 1; (i <= size) && flag; i++)
  {
      flag = 0;
      for (j=0; j < (size -1); j++)
     {
           if (a[j+1].priority > a[j].priority)
          {
                temp = a[j];             // Switch elements
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;               // Flag if switched
           }
      }
  }
}
