#include "../src/game.h"
#include "../src/queue.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/*
int rand_0_n(int n)
{
  srand(time(0));
  int r = (rand() % n);
  return (r);
}
*/

//TODO : pas satisfait perso

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
}
