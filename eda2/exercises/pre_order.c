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
int empty(celula *stack) {return(stack->prox == NULL);}

void pre_ordem(no *raiz)
{
    celula *stack = stack_init();
    empilha (stack, raiz);
    
    while(!empty(stack))
    {
        no *n = desempilha(stack);
        if(!n)
            continue;
        printf("%d ", n->dado);

        if(n->dir != NULL)
            empilha(stack, n->dir);
        if(n->esq != NULL)
            empilha(stack, n->esq); 
    }
    printf("\n");
}