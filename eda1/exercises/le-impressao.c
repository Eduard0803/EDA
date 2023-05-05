#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void imprime(celula *le){
    celula *aux = le->prox;
    while(aux != NULL){
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le){
    celula *aux = le->prox;
    if(aux != NULL){
        printf("%d -> ", aux->dado);
        imprime_rec(aux);
    }
    else
        printf("NULL\n");
}
