#include "tri.h"
#include <stdio.h>


void tri_insertion_teddy(struct teddy *list[], int len)
{
    struct teddy *new[len];
    new[0] = list[0];
    int len_new = 1;
    while (len_new != len)
    {
        struct teddy *element = list[len_new];
        int condition = 0;
        int index_element = 0;
        while (condition != 1)
        {
            if (index_element == len_new)
            {
                condition = 1;
            }
            else if (condition != 1 && element->equiv_Honey > new[index_element]->equiv_Honey)
            {
                condition = 1;
            }

            else
            {
                index_element++;
            }
        }
        for (int index = len_new; index > index_element; index--)
        {
            new[index] = new[index-1];
        }
        new[index_element] = element;
        len_new++;
        index_element = 0;
    }
    for (int i = 0; i < len; i++)
    {
        list[i] = new[i];
    }
}
