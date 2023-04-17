typedef int Item;

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a;a=b;b=t;}
#define cmpexch(a, b) {if(less(b, a))exch(a, b)}

void selection_sort(Item *p, int l, int r){
    int i, min = l;

    if(r == l)
        return;
    for(i=min+1; i<=r; i++){
        cmpexch(p[min], p[i])
    }
    selection_sort(p, l+1, r);
}
