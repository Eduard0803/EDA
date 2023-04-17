#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 4200000

typedef struct{
    char string[MAX_TAM];
}Item;

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
    if(h->ultimo == NULL)
        h->ultimo = novo_no;
    h->size++;
    return 1;
}

int insere_depois(header_st *h, no_st *no, Item e) // insere o Item depois do nó que recebeu
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = no->prox;
    no->prox = novo_no;
    if(no == h->ultimo)
        h->ultimo = novo_no;
    h->size++;
    return 1;
}

void remove_inicio(header_st *h) // remove o Item que está no inicio da lista
{
    no_st *to_remove = h->inicio;
    h->inicio = h->inicio->prox;
    h->size--;
    free(to_remove);
}

int n_concatenacoes(const char *string, const char *search, int tam_search);
Item buffer;

int main(int *argc, char *argv[])
{
    header_st *h = malloc(sizeof(header_st));
    int tam_string;

    inicializa_lista(h);
    strcpy(buffer.string, "Eduardo");
    insere_inicio(h, buffer);

    while(scanf(" %s%n", buffer.string, &tam_string) != EOF)
        insere_depois(h, h->ultimo, buffer);

    remove_inicio(h);
    tam_string--;
    int limit = h->size;

    for(int i=0; i<limit-1; i++){
        printf("%d\n", n_concatenacoes(h->inicio->e.string, buffer.string, tam_string));
        remove_inicio(h);
    }
}

/*

internet novidade absurdamente articulada compulsoriamente dentro dos conformes me

0 0 1 0 1 0 0 1

alegria dura pouco quando estamos alegres por motivos obscuros A

*/

int n_concatenacoes(const char *string, const char *search, int tam_search)
{
    int count=0;
    const char *ptr = string;

    while(ptr = strstr(ptr, search)){
        count++;
        ptr += tam_search;
    }
    return count;
}