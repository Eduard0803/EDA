#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula* enfileira(celula *f, int x){
    celula *novo_no = (celula*)malloc(sizeof(celula));
    novo_no->prox = f->prox;
    f->prox = novo_no;
    f->dado = x;
    return novo_no;
}
