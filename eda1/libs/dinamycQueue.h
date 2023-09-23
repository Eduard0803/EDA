#include <stdlib.h>
// implementação da fila em uma lista encadeada
typedef int Item; // define o tipo Item
typedef struct no_st{ // define cada nó da lista
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{ // define a fila
    no_st *primeiro;
    int size;
    no_st *ultimo;
}fila_st;

int inicializa_fila(fila_st *f){ // inicializa a fila
    f->primeiro = NULL;
    f->ultimo = NULL;
    f->size = 0;
    return 1;
}

int enfila(fila_st *f, Item e){
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL)
        return 0;
    novo_no->e = e;
    novo_no->prox = NULL;
    if(f->primeiro == NULL){ // se a fila tiver vazia insere no inicio
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{ // senão no final da fila
        f->ultimo->prox = novo_no;
        f->ultimo = novo_no;
    }
    f->size++;
    return 1;
}

Item desenfila(fila_st *f){ // remove o primeiro elemento da fila
    no_st *to_remove = f->primeiro;
    Item ret = to_remove->e;
    f->primeiro = f->primeiro->prox;
    free(to_remove);
    f->size--;
    return ret;
}

Item espia(fila_st *f){return f->primeiro->e;} // retorna o primeiro elemento da fila
int empty(fila_st *f){return f->size == 0;} // retorna True se estiver vazia e False senão

void imprime_fila(no_st *no){ // imprime a fila no console
    if(no == NULL)
        return;
    printf("%d\n", no->e);
    imprime_fila(no->prox);
}

int imprime_fila_in_file(no_st *no, char *file_name){ // imprime a fila no arquivo
    FILE *arq = fopen(file_name, "a");
    if(arq == NULL || no == NULL)
        return 0;
    fprintf(arq, "%d\n", no->e);
    fclose(arq);
    imprime_fila_in_file(no->prox, file_name);
}

void inverte_fila(fila_st *f){ //inverte a ordem da fila
    f->ultimo = f->primeiro;
    no_st *aux = f->primeiro;
    no_st *tmp = aux->prox;
    
    while(tmp != NULL){
        no_st *t = tmp->prox;
        tmp->prox = aux;
        aux = tmp;
        tmp = t;
    }
    f->primeiro = aux;
    f->ultimo->prox = NULL;
}
