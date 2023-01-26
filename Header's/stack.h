#include <stdlib.h>

typedef int Item;

struct stack_st{
    Item *v;
    int topo, size;
};

int incializa_stack(struct stack_st *p, int s)
{
    p->v = malloc(sizeof(Item)*s);

    if(p->v == NULL)
        return 0;

    p->size = s;
    p->topo = 0;
    return 1;
}

int empilhar(struct stack_st *p, Item e)
{
    if(p->size == p->topo)
        return 0;
    
    p->v[p->topo++] = e;
    return 1;
}

int esta_vazia(struct stack_st *p)
{
    return p->topo == 0;
}

int topo(struct stack_st *p)
{
    return p->v[p->topo-1];
}

void desempilha(struct stack_st *p)
{
    p->topo--;
}

void copy_stack(struct stack_st *p1, int l1, int r1, struct stack_st *p2, int l2)
{
    int i, l2_buffer=l2;
    for(i=l1; i<=r1; i++){
        p2->v[l2_buffer++] = p1->v[i];
    }
}
