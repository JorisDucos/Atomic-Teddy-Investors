#include "stockex.h"


const struct stockex s = {"Catane", 2, { {{{10, 1, 0}},{{0, 0, 1}}},{{{0, 0, 1}},{{10, 0, 0}}} }}; 

const struct stockex* starting_stockex()
{ 
  return(&s);
}


const char* stockex_name(const struct stockex* s)
{
  const char* stockex_name = (*s).name;
  return(stockex_name);
}


size_t stockex__num_transactions(const struct stockex* t)
{
  return((*t).nb_transac);
}

const struct transac* stockex__transaction(const struct stockex* s, size_t num)
{
  return (&s->transacs[num]);
}

struct wallet transac__in_wallet(const struct transac* s)
{
  struct wallet transac = (*s).good_in;
  return(transac);
}

struct wallet transac__out_wallet(const struct transac* s)
{
  struct wallet transac = (*s).good_out;
  return(transac);
}


