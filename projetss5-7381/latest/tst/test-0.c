#include "../src/game.h"
#include "../src/queue.h"
#include "../src/stockex.h"
#include "../src/rng.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>


void error_or_checked(char *label, int true_false)
{
  if (true_false == 1) //Error
  {
    printf("%s ----> ", label);
    printf("\033[0;31m"); //Set the text to the color red
    printf("Error \n");
    exit(EXIT_FAILURE);
  }
  else //Checked
  {
    printf("%s ----> ", label);
    printf("\033[0;32m"); //Set the text to the color green
    printf("OK \n");
  }
  printf("\033[0m"); // Reset the color
}

int main()
{
  int n = 10;
  printf("n : %d \n",n);
  srand(5);
  teddy_init();
  //Test if the number of teddies pushed in the queue is correct
  struct queue q = queue__new();
  for (int i = 0; i < n; i = i + 1)
  {
    queue__push(&q, i, &all_teddy[i]); //TODO : push teddy with same prio --> modif on queue needed

  }
  if (q.nbr_of_teddies == n)
  {
    error_or_checked("Nbre of teddies", 0);
  }
  else
  {
    error_or_checked("Nbre of teddies", 1);
  }
  for (int i = 0; i < n; i = i + 1)
  {
    if (q.list[i]->id != i)
    {
      error_or_checked("Presence of teddies", 1);
    }
  }
  error_or_checked("Presence of teddies", 0);
  struct teddy *active_teddy_test = queue__pop(&q, n);
  if (active_teddy_test->id != 0)
  {
    error_or_checked("Teddy prio", 1);
  }
  error_or_checked("Teddy prio", 0);
 
  //Test good string
  //The first good in the enum is the honey, so the good__tring function should return Honey
  if(strcmp(good__string(1), "Honey"))
    {
      error_or_checked("Good string is working",0);
    }
  else
    {
      error_or_checked("Good string is working",1);
    }

  // Test if the starting stockex is Catane
  const struct stockex* start_stockex= starting_stockex();
  if (strcmp(start_stockex->name, "Catane")==0)
    {
      error_or_checked("Good starting stockex",0);
    }
  else
    {
      error_or_checked("Good starting stockex",1);
    }
 
  //Test if a transac is possible or not
  struct wallet before_transac1={{20,0,0}};
  struct wallet after_transac1={{10,0,1}};
  int tab_of_data1[3]={10,0,0};
  if(transac_possible(before_transac1, after_transac1, tab_of_data1)==0)
    error_or_checked("Allow a possible transaction",0);
  else 
    error_or_checked("Allow a possible transaction",1);
  
  struct wallet before_transac2={{10,0,0}};
  struct wallet after_transac2={{20,0,1}};
  int tab_of_data2[3]={20,0,0};
  if(transac_possible(before_transac2, after_transac2, tab_of_data2)==1)
    {
      error_or_checked("Block an impossible transaction",0);
    }
  else
    {
      error_or_checked("Block an impossible transaction",1);
    }

  //Test if a transaction is sending to the correct next transaction
  //The first transaction of Toulouse is supposed to send the teddy in Catane
  const struct transac transac1_tls= {1, {{10, 1, 0}}, {{0, 0, 1}}, 0};
  if (strcmp((transac__next_stockex(&transac1_tls)->name), "Catane")==0)
    {
      error_or_checked("A transaction is sending to a new stockex",0);
    }
  else
    {
      error_or_checked("A transaction is sending to a new stockex",1);
    }
  
  //Test sorting function 
  for (int i = 0; i < n; i = i + 1)
  {
    q.list[i]->equiv_Honey = i;
  }
  tri_insertion_teddy(q.list, 10);
  if (q.list[0]->id==9)
    {
      error_or_checked("The sorting function is working",0);
    }
  else
    {
      error_or_checked("The sorting function is working",1);
    }
  
  //Test RNG
  int rand=rng(10);
  if(0<rand && rand<10)
    {
      error_or_checked("The RNG function is working",0);
    }
  else
    {
      error_or_checked("The RNG function is working",1);
    }
}

