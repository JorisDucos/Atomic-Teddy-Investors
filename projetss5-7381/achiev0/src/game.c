#include "game.h"
#include "rules.h"
#include "tri.h"

//Return a random number between 0 and n
int rand_0_n(int n) //int seed)
{
  int r = (rand() % n);
  return (r);
}
int play(struct teddy *t, int rng_initial)
{
  // printf("/////////////////////// PLAY ////////////////// \n");
  if (rng_initial != 0)
  {
    srand(seed);
  }
  int num_transac = rand_0_n((stockex__num_transactions((starting_stockex()))));
  const struct transac *transaction = stockex__transaction(starting_stockex(), num_transac);
  int N = rand_0_n(MAX_TRANSAC_ONE_TIME);
  printf("N : %d \n", N);
  struct wallet wallet_to_add = transac__out_wallet(transaction);
  // printf("in : %d \n",wallet_to_add.data[0]);
  struct wallet wallet_to_remove = transac__in_wallet(transaction);
  // printf("out : %d \n",wallet_to_remove.data[0]);
  struct wallet wallet_before = t->wallet;
  for (int w = 0; w < MAX_GOOD; w++)
  {
    t->wallet.data[w] = t->wallet.data[w] + N * (wallet_to_add.data[w]);
    // printf("i : %d ---- %d \n",w,t->wallet.data[w]);
    t->wallet.data[w] = t->wallet.data[w] - N * (wallet_to_remove.data[w]);
    // printf("i : %d ---- %d \n",w,t->wallet.data[w]);
  }
  struct wallet wallet_after = t->wallet;
  if (kick_or_keep(t,transac_possible(wallet_before,wallet_after)) == 0)
  {
    return 0;
  }
  if (N == 0)
  {
    return 1;
  }
  return 1 + log2(N);
}

/*
void display_results(int players_left,struct queue q)
{

}
*/

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