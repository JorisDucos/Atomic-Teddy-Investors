#include "rules.h"


int transac_possible(struct wallet before_transac, struct wallet after_transac, int tab_of_data[])
{

    for (int i = 0; i < MAX_GOOD; i++)
    {
        if (before_transac.data[i] < after_transac.data[i] && tab_of_data[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}

int kick_or_keep(struct teddy *t, int result_transac_possible)
{
    if (result_transac_possible == 1)
    {
        printf("OH NON ! Le teddy n°%d a essayé de tricher ! Il est exclu de la partie ! \n", t->id);
        return 1;
    }
    return 0;
}
