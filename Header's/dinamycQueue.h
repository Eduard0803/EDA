#include <stdlib.h>

typedef int Item;

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

Item espia(fila_st *f)
{
    return f->primeiro->e;
}

int empty(fila_st *f)
{
    return f->size == 0;
}

void imprime_fila(no_st *no)
{
    if(no == NULL)
        return;
    printf("%d\n", no->e);
    imprime_fila(no->prox);
}
