#define key(a) a
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a;a=b;b=t;}
#define cmpexch(a, b) {if(less(b, a))exch(a, b)}

typedef int Item;

void bubble_sort(Item *p, int l, int r){
    int i, j;
    for(i=l; i<r; i++)
        for(j=l; j<r; j++)
            cmpexch(p[j], p[j+1]);
}
