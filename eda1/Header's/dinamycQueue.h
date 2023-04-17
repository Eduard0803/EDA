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

Item espia(fila_st *f) // retorna o primeiro elemento da fila 
{
    return f->primeiro->e;
}

int empty(fila_st *f) // retorna True se estiver vazia e False senão
{
    return f->size == 0;
}

void imprime_fila(no_st *no) // escreve no console todos os elemento da fila apartir do no recebido
{
    if(no == NULL)
        return;
    printf("%d\n", no->e);
    imprime_fila(no->prox);
}

int imprime_fila_in_file(no_st *no, char *file_name) // escreve no arquivo todos os elemento da fila apartir do no recebido
{
    FILE *arq = fopen(file_name, "a");
    if(arq == NULL || no == NULL)
        return 0;
    fprintf(arq, "%d\n", no->e);
    fclose(arq);
    imprime_fila_in_file(no->prox, file_name);
}

void inverte_fila(fila_st *f) //inverte a fila, assim o primeiro elemento passa a ser o ultimo e o ultimo o primeiro
{
    f->ultimo = f->primeiro;
    no_st *aux = f->primeiro;
    no_st *tmp = aux->prox;
    
    while(tmp != NULL)
    {
        no_st *t = tmp->prox;
        tmp->prox = aux;
        aux = tmp;
        tmp = t;
    }
    f->primeiro = aux;
    f->ultimo->prox = NULL;
}
