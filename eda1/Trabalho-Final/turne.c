#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[30];
    char first, last;
}Item;

typedef struct no_st{
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{
    no_st *primeiro;
    int size;
    no_st *ultimo;
}fila_st;

int inicializa_fila(fila_st *f)
{
    f->primeiro = NULL;
    f->ultimo = NULL;
    f->size = 0;
    return 1;
}

int enfila(fila_st *f, Item e)
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = NULL;
    if(f->primeiro == NULL){
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{
        f->ultimo->prox = novo_no;
        f->ultimo = novo_no;
    }
    f->size++;
    return 1;
}

Item desenfila(fila_st *f)
{
    no_st *to_remove = f->primeiro;
    Item ret = to_remove->e;
    f->primeiro = f->primeiro->prox;
    free(to_remove);
    f->size--;
    return ret;
}

void imprime_fila(no_st *no)
{
    if(no == NULL)
        return;
    printf("%s\n", no->e.name);
    imprime_fila(no->prox);
}

Item sai_da_fila(fila_st *f, no_st *no)
{
    no_st *aux = no->prox;
    Item ret = aux->e;
    no->prox = no->prox->prox;
    f->size--;
    free(aux);
    return ret;
}

int main()
{
    fila_st *fila = malloc(sizeof(fila_st));
    Item buffer;
    int tam, i=0;

    inicializa_fila(fila);

    while(scanf(" %s%n", buffer.name, &tam) != EOF){
        if(i++ != 0)
            tam--;
        buffer.first = buffer.name[0];
        buffer.last = buffer.name[tam-1];
        enfila(fila, buffer);
    }

    no_st *aux = fila->primeiro;
    int count = fila->size;

    while(--count)
    {
        if((aux->e.last)-32 == aux->prox->e.first)
            enfila(fila, sai_da_fila(fila, aux));
        if(aux->prox == NULL)
            break;
        aux = aux->prox;
    }
    imprime_fila(fila->primeiro);
    free(fila);
}
/*
Oiapoque Estrela Abaetetuba

Brasilia Americana IlhaSolteira SaoPaulo OuroPreto

Rondonopolis Mirandopolis Salete Itaituba Imperatriz Zacarias Manaus SaoJoao Ocara Aracatuba
*/