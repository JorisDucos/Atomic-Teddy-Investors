#ifndef RULES_H
#define RULES_H

#include "queue.h"

#include <stdio.h>


//Check if a transaction is possible or not
int transac_possible(struct wallet before_transac,struct wallet after_transac,int tab_of_data[]);

//Decide if a teddy is kicked or not
int kick_or_keep(struct teddy *t, int result_transac_possible);


#endif
