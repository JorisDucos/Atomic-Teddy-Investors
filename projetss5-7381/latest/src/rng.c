//Return a random number between 0 and n
#include "rng.h"


int rng(int n) //int seed)
{
  int r = (rand() % n);
  return (r);
}
