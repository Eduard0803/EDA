#include <stdio.h>

typedef int Item;

void delete_pivo(Item *v, int l, int pivo, int r)
{
    int ia=pivo;

    while(ia < r){
        v[ia] = v[ia+1];
        ia++;
    }
}
