#include <stdlib.h>

typedef int Item;

typedef struct no_st{
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{
    no_st *inicio;
    int size;
    no_st *ultimo;
}stack_st;

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

Item topo(stack_st *p) // retorna o item que está no topo da pilha
{
    return p->inicio->e;
}

int esta_vazia(stack_st *p) // retorna True se a pilha estiver vazia, senão retorna False
{
    return p->size == 0;
}
