#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

int remove_depois(celula *p){
    if(p->prox != NULL){
        celula *aux = p->prox;
        p->prox = p->prox->prox;
        free(aux);
        return 0;
    }
}

void remove_elemento (celula *le, int x){
    celula *aux = le->prox, *cloud = le;

    while(aux != NULL){
        if(aux->dado == x){
            remove_depois(cloud);
            return;
        }
        aux = aux->prox;
        cloud = cloud->prox;
    }
}

void remove_todos_elementos(celula *le, int x){
    while(le != NULL){
        if(le->prox->dado == x)
            remove_depois(le);
        le = le->prox;
    }
}