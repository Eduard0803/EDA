#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id, valor, prox_id;
}Item;

#define key(a) a.id
#define less(a, b) (key(a) < key(b))

void merge(Item *v, int l, int m, int r)
{
    Item *p = malloc(sizeof(Item) * (r-l+1));
    int ia=l, ib=m+1, iaux=0, i;

    while(ia <= m && ib <= r)
    {
        if(less(v[ia], v[ib]))
            p[iaux++] = v[ia++];
        else
            p[iaux++] = v[ib++];
    }
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

int main()
{
    int n_itens, i, indice;

    scanf("%d", &n_itens);

    Item *itens = malloc(sizeof(Item)*n_itens);
    scanf("%d %d %d", &itens[0].id, &itens[0].valor, &itens[0].prox_id);
    int proximo_id = itens[0].prox_id;

    for(i=1; i<(n_itens); i++){
        scanf("%d %d %d", &itens[i].id, &itens[i].valor, &itens[i].prox_id);
    }

    merge_sort(itens, 1, n_itens-1);

    printf("%d\n", itens[0].valor);
    while(proximo_id != -1){
        indice = binary_search(itens, proximo_id, 1, n_itens-1);
        proximo_id = itens[indice].prox_id;
        printf("%d\n", itens[indice].valor);
    }
    free(itens);
}
