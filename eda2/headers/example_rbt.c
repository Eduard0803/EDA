#include <stdio.h>
#include <time.h>
#include "Red_Black.h"

int main(){
    srand(time(NULL));

    // insere 10 Itens na árvore
    no_st *root = insert(NULL, rand()%101);
    for(int i=0; i<9; ++i)
        root = insert(root, rand()%101);
    // imprime os Itens ordenados
    in_order(root);
    printf("\n");
}
