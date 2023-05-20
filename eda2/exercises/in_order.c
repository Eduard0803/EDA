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

celula* criapilha()
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

void em_ordem(no *raiz)
{
    celula *stack = criapilha();
    empilha (stack, raiz);
    while(1)
    {
        no *x = desempilha(stack);
        if(x != NULL)
        {
            empilha(stack, x);
            empilha(stack,x->esq);
        }
        else
        {
            if(pilhavazia(stack))
                break;
            x = desempilha(stack);
            printf("%d ", x->dado);
            empilha(stack,x->dir);
        }
    }
    printf("\n");
}
