#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "stockex.h"


#define MAX_PLYR 20


struct teddy
{
  struct wallet wallet;
  int id;
  int time;
  int equiv_Honey;
};
// This type represent a teddy

struct queue
{
  struct teddy* list[MAX_PLYR]; 
  int nbr_of_teddies;
};
// This type represent a queue

struct queue empty_queue ;
struct teddy all_teddy[MAX_PLYR] ;

struct teddy teddy_init();

struct queue  queue__new(); 
// create new empty queue

void          queue__push(struct queue* h, int priority, struct teddy* t);
 // push teddy `t` into queue `h` with priority `priority`

struct teddy* queue__top(struct queue* h); 
 // return the priority teddy in the queue `h`

struct teddy* queue__pop(struct queue* h,int queue_n); 
// return and remove the priority teddy from the queue `h`

#endif
