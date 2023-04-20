#include <stdlib.h>

#define key(a) a
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a;a=b;b=t;}

typedef int Item;

int separa(Item *v, int l, int r)
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

void quick_select(Item *v, int l, int r, int k)
{
    if(r <= l)
        return;
    int i = separa(v, l, r);
    if(i > k)
        quick_select(v, l, i-1, k);
    if(i < k)
        quick_select(v, i+1, r, k);
}
