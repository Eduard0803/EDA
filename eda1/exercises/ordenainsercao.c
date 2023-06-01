#include <stdio.h>
#include <stdlib.h>
#define key(a) a
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a;a=b;b=t;}
#define cmpexch(a, b) {if(less(b, a))exch(a, b)}

typedef int Item;

void insertion_sort(Item *v, int l, int r)
{
    int i;
    for(i=r; i>l; i--)
        cmpexch(v[i-1], v[i]);

    for(i=l+2; i<=r; i++){
        int j=i;Item tmp = v[j];
        while(less(tmp, v[j-1]))
        {v[j] = v[j-1];j--;}
        v[j] = tmp;
    }
}

int main()
{
    int v[1010], k=0;

    while(scanf("%d", &v[k++]) != EOF);

    insertion_sort(v, 0, k-2);

    for(int i=0; i<k-2; ++i)
        printf("%d ", v[i]);
    printf("%d\n", v[k-2]);
}
