

#ifndef GOOD_H
#define GOOD_H

#define MAXI_GOOD 20
#define MAX_STR 64

// An enumeration of the existing goods
enum good 
  {
    HONEY,           // Always first
    MONKEY_WRENCH,
    OUTBOARD_MOTOR,
    MAX_GOOD,        // Always last
    ERROR_GOOD = -1, // Always -1
    FIRST_GOOD=HONEY 
  };

// Contains the names for the goods
const char* string[MAX_GOOD];

// A description of a good
const char* good__string(enum good g); 

// int good_rank(char key[]); Check if it's really needed

// Contains the values of the goods
const unsigned int value[MAX_GOOD];

// The base value of a good (in equivalent-Honey)
unsigned int good__value(enum good g);

// A wallet containing different amounts of goods
struct wallet 
{
  unsigned int data[MAX_GOOD];
};

#endif