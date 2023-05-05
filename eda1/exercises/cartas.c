#include <stdio.h>
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

int enfila(fila_st *f, Item e) // se a fila estiver vazia insere o elemento no inicio, senão insere no final da fila
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

Item desenfila(fila_st *f) // remove o primeiro elemento da fila
{
    no_st *to_remove = f->primeiro;
    Item ret = to_remove->e;
    f->primeiro = f->primeiro->prox;
    free(to_remove);
    f->size--;
    return ret;
}

int empty(fila_st *f) // retorna True se estiver vazia e False senão
{
    return f->size == 0;
}

int main()
{
    fila_st *queue = (fila_st*)malloc(sizeof(fila_st));
    int n;

    inicializa_fila(queue);
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
        enfila(queue, i);

    printf("Cartas descartadas: ");
    while(queue->size > 2){
        printf("%d, ", desenfila(queue));
        enfila(queue, desenfila(queue));
    }
    printf("%d\n", desenfila(queue));
    printf("Carta restante: %d\n", desenfila(queue));
}
