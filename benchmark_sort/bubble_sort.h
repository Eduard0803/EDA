#include "macros.h"

void bubble_sort(Item *p, int l, int r)
{
    int i, j;
    for(i=l; i<r; i++)
        for(j=l; j<r; j++)
            cmpexch(p[j], p[j+1]);
}
