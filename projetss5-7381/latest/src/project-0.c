#include "queue.h"
#include "game.h"
#include "option.h"
#include "move.h"

#include <stdio.h>

/* TODO : 
           -test 
          -if two teddies have the same priority, RNG ?
          -COMMENT
          -kick TODO
          -Usage
          -move
          

*/

//////////////////////////////////////////  MAIN
int main(int argc, char *argv[])
{
  parse_opts(argc, argv);

  teddy_init();



  struct queue q = queue__new();


  for (int i = 0; i < n; i = i + 1)
  {
    queue__push(&q, i, &all_teddy[i]); 
  }


  int global_time = 0;
  int rng_initial = 1;

  while (global_time < party_time && q.nbr_of_teddies != 0)
  {


    struct teddy *active_teddy = queue__pop(&q, n);
    global_time = active_teddy->time;
    int time_spent = play(active_teddy, rng_initial);
    if (rng_initial != 0)
    {
      rng_initial = 0;
    }

    if (time_spent != 0)
    {
      queue__push(&q, global_time + time_spent, active_teddy);
    }

  }

  display_results(q.nbr_of_teddies, q);

  return 0;
}
