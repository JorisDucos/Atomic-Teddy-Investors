#ifndef RULES_H
#define RULES_H

#include "queue.h"

#include <stdio.h>



int transac_possible(struct wallet before_transac,struct wallet after_transac);

int kick_or_keep(struct teddy *t, int result_transac_possible);


#endif
