#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a; a=b; b=t}
#define cmpexch(a, b) {if(less(b, a)) exch(a, b)}

Item* merge2(Item *v1, int l1, int r1, Item *v2, int l2, int r2);
Item* merge4(Item *v1, int l1, int r1, Item *v2, int l2, int r2, Item *v3, int l3, int r3, Item *v4, int l4, int r4);

int main()
{
    int v1[] = {1, 2, 3};
    int v2[] = {5, 6, 7};
    int v3[] = {9, 10, 11};
    int v4[] = {13, 14, 15};

    Item *r = merge4(v1, 0, 2, v2, 0, 2, v3, 0, 2, v4, 0, 2);

    int i;
    printf("%d", r[0]);
    for(i=1; i<12; i++)
        printf(" %d", r[i]);
    printf("\n");
}

Item* merge2(Item *v1, int l1, int r1, Item *v2, int l2, int r2)
{
    Item *p = malloc(sizeof(Item) * ((r1-l1+1) + (r2-l2+1)));
    int ia=l1, ib=l2, iaux=0;

    while(ia <= r1 && ib <= r2)
    {
        if(less(v1[ia], v2[ib]))
            p[iaux++] = v1[ia++];
        else
            p[iaux++] = v2[ib++];
    }
    while(ia <= r1)
        p[iaux++] = v1[ia++];
    while(ib <= r2)
        p[iaux++] = v2[ib++];
    return p;
}

Item* merge4(Item *v1, int l1, int r1, Item *v2, int l2, int r2, Item *v3, int l3, int r3, Item *v4, int l4, int r4)
{
    Item *p1 = merge2(v1, l1, r1, v2, l2, r2);
    Item *p2 = merge2(v3, l3, r3, v4, l4, r4);
    return merge2(p1, 0, ((r1-l1+1)+(r2-l2+1)), p2, 0, ((r3-l3+1)+(r4-l4+1)));
}