typedef int Item;

#define key(a) (a)

int binary_search(Item *p, int x, int inicio, int fim)
{
    int meio = (inicio+fim)/2;
    
    if(inicio > fim)
        return -1;

    if(x > key(p[meio]))
        return binary_search(p, x, meio+1, fim);
    if(x < key(p[meio]))
        return binary_search(p, x, inicio, meio-1);
    if(key(p[meio]) == x)
        return meio;
}
