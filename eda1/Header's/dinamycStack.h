#include <stdlib.h>
// implementação da pilha em uma lista encadeada
typedef int Item; // define o tipo Item
typedef struct no_st{ // define cada nó da lista
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{ // define a pilha
    no_st *inicio;
    int size;
    no_st *ultimo;
}stack_st;

int inicializa_stack(stack_st *p){ // inicializa a pilha
    p->inicio = NULL;
    p->ultimo = NULL;
    p->size = 0;
    return 1;
}

int empilha(stack_st *p, Item e){ // empilha o Item
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = p->inicio;
    p->inicio = novo_no;
    p->size++;
    return 1;
}

Item desempilha(stack_st *p){ // desempilha o Item
    no_st *to_remove = p->inicio;
    p->inicio = p->inicio->prox;
    Item ret = to_remove->e;
    free(to_remove);
    p->size--;
    return ret;
}

Item top(stack_st *p){return p->inicio->e;} // retorna o item que está no topo da pilha
int empty(stack_st *p){return p->size == 0;} // retorna 'True' se a pilha estiver vazia
