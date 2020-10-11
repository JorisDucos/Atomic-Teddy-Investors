#include "queue.h"
#include "game.h"
#include "option.h"

#include <stdio.h>

/* TODO : 
           -test 
          -if two teddies have the same priority, RNG ?
           ~ display_results
          -Pb with good__value
          -COMMENT
          -kick TODO
          

*/

//////////////////////////////////////////  MAIN
int main(int argc, char *argv[])
{
  parse_opts(argc, argv);
  //printf("%d \n", party_time);
  printf("%d \n", seed);
  // printf("%d \n", n);
  teddy_init();
  struct queue q = queue__new();
  for (int i = 0; i < n; i = i + 1)
  {
    queue__push(&q, i, &all_teddy[i]); //TODO : push teddy with same prio --> modif on queue needed
  }
  int global_time = 0;
  int rng_initial = 1;
  // int i = 0; //TODO : Tej
  while (global_time < party_time && q.nbr_of_teddies != 0)
  {
    struct teddy *active_teddy = queue__pop(&q, n);
    // printf("teddy : %d \n", active_teddy->id);
    // printf("time : %d \n", active_teddy->time);
    //for (int w = 0; w < q.nbr_of_teddies; w++)
    //{
    //printf("teddy n* %d ok \n", q.list[w]->id);
    //}
    global_time = active_teddy->time;
    int time_spent = play(active_teddy, rng_initial);
    if (rng_initial != 0)
    {
      rng_initial = 0;
    }
    // printf("time spent : %d \n", time_spent);

    /*
      printf("after play teddy : %d \n",active_teddy->id);
      printf("global_time : %d ----------",global_time);
      printf("time_spent %d  \n",time_spent);
      */

    // global_time=global_time+MAX_PARTY_TIME-1;
    if (time_spent != 0)
    {
      queue__push(&q, global_time + time_spent, active_teddy);
    }
    /* 
    //TODO : tej
    for (int w = 0; w < n; w++)
    {
      printf("teddy n* %d ok \n", q.list[w]->id);
    }
    // i++; // TODO : tej
    */
  }
  /*
  for (int i = 0;i<n;i++)
  {
    printf("id : %d ----- wallet : %d \n",q.list[i]->id,q.list[i]->wallet.data[2]);
  }
  */
  printf("%d \n", seed);
  printf("il reste : %d teddy \n",q.nbr_of_teddies);
  
  display_results(q.nbr_of_teddies, q);

  return 0;
}