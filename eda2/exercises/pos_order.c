#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq, *dir;
}no;

typedef struct celula{
    no *conteudo;
    struct celula *prox;
}celula;

celula* stack_init()
{
    celula *stack = malloc(sizeof(celula));
    stack->prox = NULL;
    return stack;
}

void empilha(celula *stack, no *r)
{ 
    celula *novo_no = malloc(sizeof(celula));
    novo_no->conteudo = r;
    novo_no->prox = stack->prox;
    stack->prox = novo_no; 
}

no* desempilha(celula *stack) {
    celula *old = stack->prox;
    no *r = old->conteudo;
    stack->prox = old->prox;
    free(old);
    return r; 
}
int pilhavazia(celula *stack) {return(stack->prox == NULL);}

void pos_ordem(no *raiz)
{
    celula *stack = stack_init(), *stack_2 = stack_init();
    empilha(stack, raiz);

    while(!pilhavazia(stack))
    {
        no *n = desempilha(stack);
        if(!n) 
            continue;
        empilha(stack_2, n);

        if(n->esq)
            empilha(stack, n->esq);
        if(n->dir)
            empilha(stack, n->dir);
    }
    while(!pilhavazia(stack_2))
    {
        no *print = desempilha(stack_2);
        printf("%d ", print->dado);
    }
    printf("\n");
}
