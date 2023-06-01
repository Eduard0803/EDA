#include <stdio.h>
#include <stdlib.h>
#define key(a) a
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a;a=b;b=t;}
#define cmpexch(a, b) {if(less(b, a))exch(a, b)}

typedef int Item;

void bubble_sort(Item *p, int l, int r)
{
    int i, j;
    for(i=l; i<r; i++)
        for(j=l; j<r; j++)
            cmpexch(p[j], p[j+1]);
}

int main()
{
    int v[1010], k=0;

    while(scanf("%d", &v[k++]) != EOF);

    bubble_sort(v, 0, k-2);

    for(int i=0; i<k-2; ++i)
        printf("%d ", v[i]);
    printf("%d\n", v[k-2]);
}
