#include <stdio.h>
#include <stdlib.h>
#define key(a) a
#define less(a, b) (key(a) < key(b))

typedef int Item;

void merge(Item *v, int l, int m, int r){
    Item *p = malloc(sizeof(Item) * (r-l+1));
    int ia=l, ib=m+1, iaux=0, i;

    while(ia <= m && ib <= r)
        if(less(v[ia], v[ib]))
            p[iaux++] = v[ia++];
        else
            p[iaux++] = v[ib++];
    while(ia <= m)
        p[iaux++] = v[ia++];
    while(ib <= r)
        p[iaux++] = v[ib++];

    iaux = 0;
    for(i=l; i<=r; i++)
        v[i] = p[iaux++];
    free(p);
}

void merge_sort(Item *v, int l, int r)
{
    if(r-l == 0)
        return;
    int m = (r+l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

int main()
{
    int v[1010], n;

    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &v[i]);

    merge_sort(v, 0, n-1);

    for(int i=0; i<n-1; ++i)
        printf("%d ", v[i]);
    printf("%d\n", v[n-1]);
}
