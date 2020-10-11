#include "queue.h"
#include <stdio.h>

struct teddy teddy_init()
{
  for (int i = 0; i <= MAX_PLYR; i = i + 1)
  {
    all_teddy[i].wallet.data[0] = 1000;
    all_teddy[i].wallet.data[1] = 0;
    all_teddy[i].wallet.data[2] = 0;
    all_teddy[i].id = i;
    all_teddy[i].time = 0;
  }
  return (*all_teddy);
}

struct queue empty_queue = {{}, 0};

struct queue queue__new()
{
  return (empty_queue);
}

void queue__push(struct queue *h, int priority, struct teddy *t)
{
  t->time = priority;
  (h->list[h->nbr_of_teddies]) = t;
  h->nbr_of_teddies = (h->nbr_of_teddies) + 1;
}

struct teddy *queue__top(struct queue *h)
{
  int teddy_ref_time = (h->list[0])->time;
  int teddy_top = 0;
  for (int i = 0; i < (h->nbr_of_teddies) - 1; i = i + 1) //(h->nbr_of_teddies) - 1 because the latest is always the previous player
  {
    if (((h->list[i])->time) < teddy_ref_time)
    {
      teddy_ref_time = (h->list[i])->time;
      teddy_top = i;
    }
  }
  return (h->list[teddy_top]);
}

struct teddy *queue__pop(struct queue *h,int queue_n) 
{
  struct teddy *teddy_top = queue__top(h);
  int index_teddy_top = queue_n;
  for (int i = 0; i < h->nbr_of_teddies; i = i + 1)
  {
    if (i > index_teddy_top)
    {
      h->list[i - 1] = h->list[i];
    }
    if (teddy_top->id == h->list[i]->id)
    {
      index_teddy_top = i;
    }
  }
  h->nbr_of_teddies = (h->nbr_of_teddies) - 1;
  return (teddy_top);
}
