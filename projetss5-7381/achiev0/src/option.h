#ifndef OPTION_H
#define OPTION_H 

#define MAX_PARTY_TIME  18//TODO : Put the good value


//TODO : Explain in the report the absence of static

// Global seed for the random number generator
int seed;

// Number of teddies
int n ;

// Number of turns
int party_time ;

////////////////////////////////////////////////////////////////
// Function for parsing the options of the program
// Currently available options are :
// -s <seed> : sets the seed
// -n <number of players> : sets the numbers of teddy
// -m <number of turns> : sets the number of turn
void parse_opts(int argc, char* argv[]);

#endif