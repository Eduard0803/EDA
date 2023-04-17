#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 102

typedef struct{
    char str[TAM_STR];
}Item;

typedef struct no_st{
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{
    no_st *inicio;
    int no_cout;
    no_st *ultimo;
}header_st;

struct stack_st{
    Item *v, topo;
    int size;
    header_st h;
};

int inicializa_stack(struct stack_st *p)
{
    p->h.inicio = NULL;
    p->h.ultimo = NULL;
    p->h.no_cout = 0;
    p->size = p->h.no_cout;
    return 1;
}

int empilhar(struct stack_st *p, Item e)
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = p->h.inicio;
    p->h.inicio = novo_no;
    p->h.no_cout++;
    return 1;
}

Item desempilhar(struct stack_st *p)
{
    no_st *to_remove = p->h.inicio;
    p->h.inicio = p->h.inicio->prox;
    Item ret = to_remove->e;
    free(to_remove);
    p->h.no_cout--;
    return ret;
}

int esta_vazia(struct stack_st *p)
{
    return p->h.no_cout == 0;
}

int main()
{
    struct stack_st *stack = malloc(sizeof(struct stack_st));
    char input[11];
    Item buffer;

    inicializa_stack(stack);

    while(scanf(" %s", input) != EOF){
        if(strcmp(input, "inserir") == 0){
            scanf(" %[^\n]", buffer.str);
            empilhar(stack, buffer);
        }
        if(strcmp(input, "desfazer") == 0 && esta_vazia(stack) != 0){
            printf("NULL\n");
        }
        else if(strcmp(input, "desfazer") == 0)
            printf("%s\n", desempilhar(stack).str);
    }
}
