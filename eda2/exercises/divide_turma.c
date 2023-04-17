#include <stdio.h>
#include <stdlib.h>

#define lesseq(a, b) (a <= b)

typedef struct celula{
    char matricula[10];
    double mediaAtividades;
    double mediaProvas;
    struct celula *prox;
}celula;

void relatorioMediaAtividades(celula *le, celula *l1, celula *l2, double media)
{
    celula *aux=le->prox, *aux_1=l1, *aux_2=l2;

    while(aux != NULL){
        if(lesseq(aux->mediaAtividades, media)){
            aux_1->prox = aux;
            aux_1 = aux_1->prox;
        }
        else{
            aux_2->prox = aux;
            aux_2 = aux_2->prox;
        }
        aux = aux->prox;
    }
    aux_1->prox = NULL;
    aux_2->prox = NULL;
}
