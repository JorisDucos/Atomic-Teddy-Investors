#ifndef GAME_H
#define GAME_H

#include "stockex.h"
#include "queue.h"
#include "option.h"
#include "rules.h"
#include "tri.h"
#include "move.h"
#include "rng.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>


#define MAX_TRANSAC_ONE_TIME 5

struct stockex stockex_init();

// int as_much_as_possible(struct teddy *t, int num_transac);

int play(struct teddy *t, int rng_initial);

void display_results(int players_left, struct queue q);

#endif
