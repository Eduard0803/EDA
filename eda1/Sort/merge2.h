#include <stdlib.h>
#define key(a) a
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a; a=b; b=t}
#define cmpexch(a, b) {if(less(b, a))exch(a, b)}

typedef int Item;

Item* merge2(Item *v1, int l1, int r1, Item *v2, int l2, int r2){
    Item *p = malloc(sizeof(Item)*((r1-l1+1)+(r2-l2+1)));
    int ia=l1, ib=l2, iaux=0;

    while(ia <= r1 && ib <= r2)
        if(less(v1[ia], v2[ib]))
            p[iaux++] = v1[ia++];
        else
            p[iaux++] = v2[ib++];
    while(ia <= r1)
        p[iaux++] = v1[ia++];
    while(ib <= r2)
        p[iaux++] = v2[ib++];
    return p;
}
