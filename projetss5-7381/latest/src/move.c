#include "move.h"
#include <stdio.h>
#include <string.h>
//TODO : BOF

int where_can_i_go(struct teddy *t)
{
  int choice[stockex__num_transactions(t->localisation)];
  int discovery = 0;

  for (unsigned int i = 0; i < stockex__num_transactions(t->localisation); i++)
  {
    int already_visited = 0;
    // printf("loc : %s \n",stockex__name(t->localisation));
    const char *maybe_the_name_of_next_stockex = stockex__name(transac__next_stockex(stockex__transaction(t->localisation, i)));
    for (int w = 0; w < t->len_visited_stockex; w++)
    {
      if (strcmp(maybe_the_name_of_next_stockex, t->visited_stockex[w]) == 0)
      {
        already_visited = 1;
        break;
      }
    }
    if (already_visited != 1)
    {
      choice[i] = i;
      discovery = 1;
    }
    else
    {
      choice[i] = -1;
    }
  }
  int num_transac = -1;

  switch (discovery)
  {
  case 0:
    num_transac = rng((stockex__num_transactions((t->localisation))));
    break;

  default:
    while (num_transac == -1)
    {
      num_transac = choice[rng((stockex__num_transactions((t->localisation))))];
    }

    //const struct stockex* loc = t->localisation;
    //printf("bnla :%s \n",stockex__name(t->localisation));
    const struct transac* bla = stockex__transaction(t->localisation,num_transac);
    //printf("bnla :%s \n",stockex__name(t->localisation));
    const struct stockex* aaa = transac__next_stockex(bla);
    //printf("bnla :%s \n",stockex__name(t->localisation));
    t->visited_stockex[t->len_visited_stockex] = stockex__name(aaa);
    //printf("bnlaa :%s \n",stockex__name(t->localisation));

    /* t->localisation = loc;
    for (int i=0;i<t->len_visited_stockex+1;i++)
    {
      printf("%s \n",t->visited_stockex[i]);
    }
    printf("-------------------Next \n");
    */
    t->len_visited_stockex = t->len_visited_stockex + 1;
    break;
  }

  return num_transac;
}
