#include <stdio.h>
#include <stdlib.h>

#define key(a) a
#define eq(a, b) (key(a) == key(b))

typedef int Item;

typedef struct no_st{
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{
    no_st *inicio;
    int size;
    no_st *ultimo;
}header_st;

int inicializa_lista(header_st *h)
{
    h->inicio = NULL;
    h->inicio = NULL;
    h->size = 0;
    return 1;
}

int insere_inicio(header_st *h, Item e) // insere o Item no inicio da lista
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = h->inicio;
    h->inicio = novo_no;
    h->ultimo = novo_no;
    h->size++;
    return 1;
}

int insere_depois(no_st *no, Item e) // insere o Item depois do nó que recebeu
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = no->prox;
    no->prox = novo_no;
    return 1;
}

int append(header_st *h, Item e) // se a lista estiver vazia insere o Item no inicio, senão insere no final
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = NULL;
    if(h->inicio == NULL){
        h->inicio = novo_no;
        h->ultimo = novo_no;
    }
    else{
        h->ultimo->prox = novo_no;
        h->ultimo = novo_no;
    }
    h->size++;
    return 1;
}

Item remove_inicio(header_st *h) // remove o Item que está no inicio da lista
{
    no_st *to_remove = h->inicio;
    h->inicio = h->inicio->prox;
    Item ret = to_remove->e;
    free(to_remove);
    h->size--;
    return ret;
}

no_st* busca_lista(header_st *h, Item search) // faz uma busca e retorna um ponteiro para o no, cujo Item é igual a 'search'
{
    no_st *aux = h->inicio;
    while(aux != NULL && !eq(search, aux->e))
        aux = aux->prox;
    return aux;
}

void imprime_lista(no_st *no) // imprime a lista a partir do nó que recebeu como parametro
{
    if(no != NULL){
        printf("%d\n", key(no->e));
        imprime_lista(no->prox);
    }
}
