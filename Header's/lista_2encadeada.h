#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(a) a
#define eq(a, b) (key(a) == key(b))

typedef int Item;

typedef struct no_st{
    Item e;
    struct no_st *prox;
    struct no_st *ant;
}no_st;

typedef struct{
    no_st *inicio;
    int no_cout;
    no_st *ultimo;
}header_st;

int inicializa_lista(header_st *h)
{
    h->inicio = NULL;
    h->ultimo = NULL;
    h->no_cout = 0;
    return 1;
}

Item remove_no(header_st *h, no_st *no)
{
    no_st *aux = no;
    Item ret = no->e;
    if(no->ant == NULL){
        h->inicio = h->inicio->prox;
        h->inicio->ant = NULL;
    }
    else if(no == h->ultimo){
        h->ultimo = h->ultimo->ant;
        h->ultimo->prox = NULL;
    }
    else{
        no->ant->prox = no->ant->prox->prox;
        no->ant->prox->ant = no->ant;
    }
    h->no_cout--;
    free(aux);
    return ret;
}

int insere_no(header_st *h, no_st *no, Item e)
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    if(no == h->inicio){
        novo_no->ant = NULL;
        if(h->inicio != NULL)
            h->inicio->ant = novo_no;
        novo_no->prox = h->inicio;
        h->inicio = novo_no;
        if(h->ultimo == NULL)
            h->ultimo = novo_no;
    }
    else if(no == h->ultimo){
        novo_no->prox = NULL;
        novo_no->ant = h->ultimo;
        h->ultimo->prox = novo_no;
        h->ultimo = novo_no;
    }
    else{
        novo_no->prox = no->prox;
        no->prox = novo_no;
        novo_no->prox->ant = novo_no;
        novo_no->ant = no;
    }
    h->no_cout++;
    return 1; 
}

void esvazia_lista(header_st *h)
{
    int tam = h->no_cout;
    for(int i=0; i<tam; i++)
        remove_no(h, h->inicio);
}

no_st* busca_lista(header_st *h, Item b)
{
    no_st *aux = h->inicio;
    while(aux != NULL && !eq(b, aux->e))
        aux = aux->prox;
    return aux;
}

void imprime_lista(no_st *no){
    if(no != NULL){
        printf("%d\n", no->e);
        imprime_lista(no->prox);
    }
}

void imprime_lista_c(no_st *no){
    if(no != NULL){
        printf("%d\n", no->e);
        imprime_lista_c(no->ant);
    }
}

void sort_list(header_st *h)
{
    no_st *no_1 = h->inicio, *no_2 = no_1->prox;
    int i;
    for(i=0; i<h->no_cout; i++){
        if(no_1->e > no_2->e)
            insere_no(h, no_1->prox, remove_no(h, no_2->prox));
        no_1 = no_1->prox;
        no_2 = no_1->prox;}
}
