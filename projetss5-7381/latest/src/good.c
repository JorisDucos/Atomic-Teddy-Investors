#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "good.h"

const char* string[MAX_GOOD] = 
  {
    "Honey", "Monkey Wrench", "Outboard Motor"
  };


const char* good__string(enum good g) 
{
  if (g >= FIRST_GOOD && g < MAX_GOOD)
    return string[g];
  return NULL; 
}


const unsigned int value[MAX_GOOD] = {1,25,31}; 


// The base value of a good (in equivalent-Honey)
unsigned int good__value(enum good g)
{
  if(g >= FIRST_GOOD && g < MAX_GOOD)
    {
      return value[g];
    }
  return 0;
}
