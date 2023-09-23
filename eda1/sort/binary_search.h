#define key(a) a

typedef int Item;

int binary_search(Item *p, int x, int l, int r){
    int m = l+(r-l)/2;
    
    if(l > r)
        return -1;
    if(x > key(p[m]))
        return binary_search(p, x, m+1, r);
    if(x < key(p[m]))
        return binary_search(p, x, l, m-1);
    if(key(p[m]) == x)
        return m;
}
