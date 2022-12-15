typedef int Item;

#define swap(a, b) {Item t=a; a=b; b=t;}

void selection_sort(Item *p, int l, int r){
    int i, min = l;

    if(r == l)
        return;
    for(i=min+1; i<=r; i++){
        if(p[min] > p[i])
            swap(p[min], p[i]);
    }
    selection_sort(p, l+1, r);
}
