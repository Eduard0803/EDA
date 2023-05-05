#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void insere_inicio (celula *le, int x){
    celula *aux = (celula*)malloc(sizeof(celula));
    aux->dado = x;
    if(le->prox != NULL)
        aux->prox = le->prox;
    le->prox = aux;
}

void insere_antes (celula *le, int x, int y){
    celula *novo_no = (celula*)malloc(sizeof(celula));
    celula *aux = le->prox, *cloud = le;
    novo_no->dado = x;
    while(aux != NULL && aux->dado != y){
        aux = aux->prox;
        cloud = cloud->prox;
    }
    novo_no->prox = cloud->prox;
    cloud->prox = novo_no;
}
