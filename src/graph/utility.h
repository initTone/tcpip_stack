#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>

static inline char
mac_address_byte_conv(int mac_byte)
{
  switch(mac_byte)
  {
    case 0:
      return '0';
    case 1:
      return '1';
    case 2:
      return '2';
    case 3:
      return '3';
    case 4:
      return '4';
    case 5:
      return '5';
    case 6:
      return '6';
    case 7:
      return '7';
    case 8:
      return '8';
    case 9:
      return '9';
    case 10:
      return 'A';
    case 11:
      return 'B';
    case 12:
      return 'C';
    case 13:
      return 'D';
    case 14:
      return 'E';
    case 15:
      return 'F';
    default:
      return mac_byte;
  }
}

static inline char
random_nuber()
{
  return mac_address_byte_conv(rand() % 16);
};


#endif // UTILITY_H
