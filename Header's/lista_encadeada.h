#include <stdlib.h>
#include <string.h>

#define key(a) a
#define eq(a, b) (key(a) == key(b))
#define eq_atr(a, b) (strcmp(a, b) == 0)
#define NULL_ITEM (Item){0}
#define IS_NULL_ITEM(a) {if(a == 0)}
#define TAM_NAME 30

typedef int Item;

typedef struct no_st{
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{
    no_st *inicio;
    int no_cout;
    no_st *ultimo;
}header_st;

int inicializa_lista(header_st *h)
{
    h->inicio = NULL;
    h->inicio = NULL;
    h->no_cout = 0;
    return 1;
}

int insere_inicio(header_st *h, Item e)
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = h->inicio;
    h->inicio = novo_no;
    h->no_cout++;
    return 1;
}

Item remove_inicio(header_st *h)
{
    no_st *to_remove = h->inicio;
    h->inicio = h->inicio->prox;
    Item ret = to_remove->e;
    free(to_remove);
    h->no_cout--;
    return ret;
}

int insere_depois(no_st *no, Item e)
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = no->prox;
    no->prox = novo_no;
    return 1;
}

int insere_depois_ou_fim(header_st *h, Item e, int p)
{
    int i=0;
    no_st *aux = h->inicio;
    while(i<p && aux->prox != NULL){
        aux = aux->prox;
        i++;
    }
    if(insere_depois(aux, e) == 0)
        return 0;
    h->no_cout++;
    return 1;
}

no_st* busca_lista(header_st *h, Item b)
{
    no_st *aux = h->inicio;
    while(aux != NULL && !eq(b, aux->e))
        aux = aux->prox;
    return aux;
}

Item busca_lista_item(header_st *h, Item b)
{
    no_st *a = busca_lista(h, b);
    if(a != NULL)
        return a->e;
    return NULL_ITEM;
}

int insere_depois_de_item(header_st *h, Item c, Item e)
{
    no_st *a = busca_lista(h, c);
    return insere_depois(a, e);
}

void imprime_lista(no_st *no){
    if(no != NULL){
        printf("%d\n", no->e);
        imprime_lista(no->prox);
    }
}
