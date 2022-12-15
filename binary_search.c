typedef int Item;

int binary_search(Item *p, int x, int inicio, int fim)
{
    int meio = (inicio+fim)/2;
    
    if(inicio > fim)
        return -1;

    if(x > p[meio])
        return binary_search(p, x, meio+1, fim);
    if(x < p[meio])
        return binary_search(p, x, inicio, meio-1);
    if(p[meio] == x)
        return meio;
}
