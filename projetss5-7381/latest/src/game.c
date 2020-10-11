#include "game.h"
#include <string.h>

int play(struct teddy *t, int rng_initial)
{
  if (rng_initial != 0)
  {
    srand(seed);
  }
  int N = rng(MAX_TRANSAC_ONE_TIME);
  if (N == 0)
  {
    return 1;
  }
  int num_transac = where_can_i_go(t);
  //printf("num : %d \n",num_transac);
  const struct transac *transaction = stockex__transaction((t->localisation), num_transac);


  struct wallet wallet_to_add = transac__out_wallet(transaction);

  struct wallet wallet_to_remove = transac__in_wallet(transaction);

  struct wallet wallet_before = t->wallet;
  int tab_of_data[MAX_GOOD]; 
  for (int w = 0; w < MAX_GOOD; w++)
  {
    if (wallet_to_remove.data[w] != 0)
    {
      tab_of_data[w] = 1;
    }
    else
    {
      tab_of_data[w] = 0;
    }

    t->wallet.data[w] = t->wallet.data[w] + N * (wallet_to_add.data[w]);

    t->wallet.data[w] = t->wallet.data[w] - N * (wallet_to_remove.data[w]);

  }
  struct wallet wallet_after = t->wallet;
  if (kick_or_keep(t, transac_possible(wallet_before, wallet_after, tab_of_data)) == 1)
  {
    return 0;
  }
  t->localisation = transac__next_stockex(transaction);

  for (int i = 0; i < t->len_visited_stockex; i++)
  {

  }

  return 1 + log2(N);
}


void display_results(int players_left, struct queue q) //TODO : ex-aequo ?
{
  if (players_left == 0)
  {
    printf("Tous les teddy sont elimines !!! \n");
  }

  else
  {
    for (int i = 0; i < players_left; i++)
    {
      q.list[i]->equiv_Honey = 0;
      for (int good_index = 0; good_index < MAX_GOOD; good_index++)
      {
        int data_in_equiv_h = q.list[i]->wallet.data[good_index] * good__value(good_index);
        q.list[i]->equiv_Honey = q.list[i]->equiv_Honey + data_in_equiv_h;
      }
    }
    tri_insertion_teddy(q.list, q.nbr_of_teddies);
    for (int position = 0; position < players_left; position++)
    {
      printf("n° %d : teddy n° %d avec l'equivalent de %d Honey \n", position + 1, q.list[position]->id, q.list[position]->equiv_Honey);
    }
  }
}
