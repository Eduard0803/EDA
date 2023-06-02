#include <stdlib.h>
#include "macros.h"

int partition(Item *v, int l, int r)
{
  int i = l-1, j = r;
  Item c = v[r];
  for(;;){
    while(less(v[++i], c));
    while(less(c, v[--j]))
      if(j==l) break;
    if(i>=j) break;
    exch(v[i], v[j]);
  }
  exch(v[i], v[r]);
  return i;
}

void quick_sort(Item *V, int l, int r)
{
  if (r <= l)
    return;
  cmpexch(V[(l+r)/2],V[r]);
  cmpexch(V[l],V[(l+r)/2]);
  cmpexch(V[r],V[(l+r)/2]);

  int j = partition(V,l,r);
  quick_sort(V,l,j-1);
  quick_sort(V,j+1,r);
}
