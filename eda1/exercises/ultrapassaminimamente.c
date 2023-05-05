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

typedef struct{
    no_st *inicio;
    int size;
    no_st *ultimo;
}stack_st;

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

int emptyQ(fila_st *f) // retorna True se estiver vazia e False senão
{
    return f->size == 0;
}

int inicializa_stack(stack_st *p)
{
    p->inicio = NULL;
    p->ultimo = NULL;
    p->size = 0;
    return 1;
}

int empilha(stack_st *p, Item e) // empilha os itens, inserindo eles no inicio da lista
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = p->inicio;
    p->inicio = novo_no;
    p->size++;
    return 1;
}

Item desempilha(stack_st *p) // desempilha os itens, removendo eles do inicio da lista
{
    no_st *to_remove = p->inicio;
    p->inicio = p->inicio->prox;
    Item ret = to_remove->e;
    free(to_remove);
    p->size--;
    return ret;
}

int emptyS(stack_st *p) // retorna True se a pilha estiver vazia, senão retorna False
{
    return p->size == 0;
}

int main()
{
    fila_st *queue = malloc(sizeof(fila_st));
    stack_st *stack = malloc(sizeof(stack_st));
    int input=1, limit, count=0;

    inicializa_fila(queue);
    inicializa_stack(stack);

    while(input != 0){
        scanf("%d", &input);
        if(input != 0)
            enfila(queue, input);
    }
    
    scanf("%d", &limit);
    no_st *aux = queue->primeiro;

    while(aux != NULL){
        count += aux->e;
        if(count > limit){
            empilha(stack, aux->e);
            count=0;
        }
        aux = aux->prox;
    }

    while(!emptyS(stack))
        printf("%d\n", desempilha(stack));
    free(queue);
    free(stack);
}
