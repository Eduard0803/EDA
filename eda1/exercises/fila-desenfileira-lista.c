#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

int desenfileira (celula *f, int *y){
    *y = f->prox->dado;
    celula *aux = f->prox;
    f->prox = aux->prox;
    free(aux);
    return 1;
}
