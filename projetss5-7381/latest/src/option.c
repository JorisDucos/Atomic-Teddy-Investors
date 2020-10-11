#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "option.h"

int seed = 0;
int n = MAX_PLYR;
int party_time = MAX_PARTY_TIME;

void parse_opts(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "s:n:m:")) != -1)
    {
        switch (opt)
        {
        case 's':
            seed = atoi(optarg);
            break;
        case 'n':
            if (atoi(optarg) <= MAX_PLYR)
            {
                n = atoi(optarg);
            }
            else
            {
                printf("Error in usage of %s  ----- \nWarning : MAX_PLYR = %d \n",
                        argv[0],MAX_PLYR);
                exit(EXIT_FAILURE);
            }
            break;
        case 'm':
            party_time= atoi(optarg);
            break;
        default: 
            fprintf(stderr, "Usage: %s [-s seed] [-n number of players] [-m number of turns]\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }
}
