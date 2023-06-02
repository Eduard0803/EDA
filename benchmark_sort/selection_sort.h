#include "macros.h"

void selection_sort(Item *p, int l, int r)
{
    int i, min = l;

    if(r == l)
        return;
    for(i=min+1; i<=r; i++)
        cmpexch(p[min], p[i])
    selection_sort(p, l+1, r);
}
