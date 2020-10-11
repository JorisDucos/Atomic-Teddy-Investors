#include "stockex.h"
#include "rng.h"

const struct stockex *starting_stockex()
{

  const struct stockex TOULOUSE = {"Toulouse",
                                   2,
                                   {{1, {{10, 1, 0}}, {{0, 0, 1}}, 0},
                                    {1, {{0, 0, 1}}, {{10, 0, 0}}, 2}}};
  const struct stockex MANCHESTER = {"Manchester",
                                     2,
                                     {{2, {{10, 1, 0}}, {{0, 0, 1}}, 1},
                                      {2, {{0, 0, 1}}, {{10, 0, 0}}, 0}}};
  const struct stockex CATANE = {"Catane",
                                 2,
                                 {{0, {{10, 1, 0}}, {{0, 0, 1}}, 1},
                                  {0, {{0, 0, 1}}, {{10, 0, 0}}, 2}}};

  all_stockex[0] = CATANE;
  all_stockex[2] = MANCHESTER;
  all_stockex[1] = TOULOUSE;
  /*
  // Random génératior of multiples transaction
  for (int i = 0; i < 10; i++)
  {
    for (int w = 0; w < MAXI_STOCKEX; w++)
    {
      struct transac new_transac;
      int source = w;
      new_transac.id_stockex = source;
      int destination = w;
      while (destination == w)
      {
        destination = rng(MAXI_STOCKEX);
      }
      new_transac.id_next_stockex = destination;
      for (int good = 0; good < MAX_GOOD; good++)
      {
        int num_ex = rng(10);
        if (num_ex < 5)
        {
          new_transac.good_in.data[good] = num_ex;
          new_transac.good_out.data[good] = 0;
        }
        else
        {
          new_transac.good_in.data[good] = 0;
          new_transac.good_out.data[good] = num_ex;
        }
      }
      all_stockex[w].transacs[all_stockex[w].nb_transac]=new_transac;
      all_stockex[w].nb_transac++;
    }
  }
*/
  return (&(all_stockex[0]));
}

const char *stockex__name(const struct stockex *s)
{
  const char *stockex_name = (*s).name;
  return (stockex_name);
}

size_t stockex__num_transactions(const struct stockex *t)
{
  return ((*t).nb_transac);
}

const struct transac *stockex__transaction(const struct stockex *s, size_t num)
{
  return (&s->transacs[num]);
}

struct wallet transac__in_wallet(const struct transac *s)
{
  struct wallet transac = (*s).good_in;
  return (transac);
}

struct wallet transac__out_wallet(const struct transac *s)
{
  struct wallet transac = (*s).good_out;
  return (transac);
}

const struct stockex *transac__stockex(const struct transac *s)
{
  return (&(all_stockex[s->id_stockex]));
}

const struct stockex *transac__next_stockex(const struct transac *s)
{
  return (&(all_stockex[s->id_next_stockex]));
}
