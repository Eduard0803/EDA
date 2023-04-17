#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(a) a
#define less(a, b) (key(a) < key(b))

void merge(Item *v, int l, int m, int r)
{
    Item *s = malloc(sizeof(Item)*(r-l+1));
    int ia=l, ib=m+1, iaux=0;

    while(ia <= m && ib <= r)
        if(less(v[ia], v[ib]))
            s[iaux++] = v[ia++];
        else
            s[iaux++] = v[ib++];
    while(ia <= m)
        s[iaux++] = v[ia++];
    while(ib <= r)
        s[iaux++] = v[ib++];
    iaux=0;
    for(ia=l; ia<=r; ia++)
        v[ia] = s[iaux++];
    free(s);
}

void merge_sort(Item *v, int l, int r)
{
    if(r-l == 0)
        return;
    int m = l+(r-l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

int binary_search(Item *v, int s, int l, int r)
{
    if(r < l)
        return -1;
    int m = l+(r-l)/2;
    if(s < v[m])
        return binary_search(v, s, l, m-1);
    if(s > v[m])
        return binary_search(v, s, m+1, r);
    return m;
}

int main()
{
    int n, input;

    scanf("%d", &n);
    Item v[n];
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);

    merge_sort(v, 0, n-1);

    while(scanf("%d", &input) != EOF){
        if(binary_search(v, input, 0, n-1) == -1)
            printf("nao\n");
        else
            printf("sim\n");
    }
}