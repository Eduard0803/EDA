#include <stdio.h>
#include <stdlib.h>

/*
inicializa_lista - inicializa os ponteiros do 'header' como NULL e o size = 0
empty - retorna != 0 se a lista estiver vazia, caso contrario retorna 0
insere_depois - insere o Item 'e' depois do nó passado, se a lista estiver vazia insere o Item no inicio, em caso de sucesso retorna 1, caso contrario retorna 0
insere_antes - insere o Item 'e' antes do nó passado, se a lista estiver vazia insere o Item no inicio, em caso de sucesso retorna 1, caso contrario retorna 0
remove_inicio - remove o Item que esta no inicio da lista, se a lista estiver vazia, nao remove nada, nao retorna nada
remove_ultimo - remove o Item que esta no final da lista, se a lista estives vazia nao remove nada, nao retorna nada
reverseList - inverte a lista, fazendo o swap dos ponteiro 'prev' e 'prox' de cada 'node' e tambem o swap entre 'h->inicio' e 'h->ultimo', nao retorna nada
printList - escreve no console todos os Itens da lista, a partir do 'node' recebido como parametro
printListReverse - escreve no console todos os Itens da lista, anteriores ao 'node' recebido como parametro
*/

typedef int Item; // define o tipo 'Item' como um inteiro

typedef struct no_st{ // define o tipo 'no_st' como uma struct, contendo um 'Item' e dois ponteiros para o proximo 'Item' e o anterior
    Item e;
    struct no_st *prev; // ponteiro para o Item anterior
    struct no_st *prox; // ponteiro para o proximo Item 
}no_st;

typedef struct{
    no_st *inicio; // ponteiro para o primeiro Item da lista
    int size; // variavel para armazenar o tamanho da lista
    no_st *ultimo; // ponteiro para o ultimo Item da lista
}header_st;

int inicializa_lista(header_st *h) // inicializa os ponteiros de inicio e final da 'header' como NULL e o size = 0
{
    h->inicio = NULL;
    h->ultimo = NULL;
    h->size = 0;
    return 1;
}

int empty(header_st *h) // retorna verdadeiro se a lista estiver vazia, caso contrario, retorna falso
{
    return h->size == 0;
}

int insere_depois(header_st *h, no_st *no, Item e) // insere o Item depois do nó que recebeu
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL) return 0;
    novo_no->e = e;
    h->size++;
    if(h->size == 1){
        h->inicio = novo_no;
        h->ultimo = novo_no;
        novo_no->prev = NULL;
        novo_no->prox = NULL;
        return 1;
    }
    novo_no->prox = no->prox;
    if(no != h->ultimo)
        novo_no->prox->prev = novo_no;
    else
        h->ultimo = novo_no;
    novo_no->prev = no;
    no->prox = novo_no;
    return 1;
}

int insere_antes(header_st *h, no_st *no, Item e) // insere o Item antes do 'node' que recebeu
{
    no_st *novo_no = malloc(sizeof(no_st));
    if(novo_no == NULL) return 0;

    novo_no->e = e;
    h->size++;
    if(h->size == 1){
        h->inicio = novo_no;
        h->ultimo = novo_no;
        novo_no->prev = NULL;
        novo_no->prox = NULL;
        return 1;
    }
    if(no != h->inicio)
        no->prev->prox = novo_no;
    else
        h->inicio = novo_no;
    novo_no->prev = no->prev;
    novo_no->prox = no;
    no->prev = novo_no;
    return 1;
}

void remove_inicio(header_st *h) // remove o primeiro Item da lista
{
    if(empty(h)) return;
    no_st *to_remove = h->inicio;
    h->inicio = h->inicio->prox;
    if(h->inicio != NULL)
        h->inicio->prev = NULL;
    h->size--;
    free(to_remove);
}

void remove_ultimo(header_st *h) // remove o ultimo Item da lista
{
    if(empty(h)) return;
    no_st *to_remove = h->ultimo;
    h->ultimo = h->ultimo->prev;
    if(h->ultimo != NULL)
        h->ultimo->prox = NULL;
    h->size--;
    free(to_remove); 
}

#define swap_no(a, b) {no_st *t=a;a=b;b=t;} // macro para fazer o swap entre os 'node'
#define swap_walk_no(a) {swap_no(a->prev, a->prox);a=a->prev;} // macro para fazer o swap entre os 'node' e avancar para o proximo 'node'
void reverseList(header_st *h) // inverte a lista
{
    no_st *aux = h->inicio;
    while(aux != NULL)
        swap_walk_no(aux);
    swap_no(h->inicio, h->ultimo);
}

void printList(no_st *no) // escreve todo os itens a partir do 'node' que recebeu
{
    if(no != NULL){
        printf("%d ", no->e);
        printList(no->prox);
    }
}

void printListReverse(no_st *no) // escreve todos os Itens da lista ao contrario, a partir do 'node' que recebeu
{
    if(no != NULL){
        printf("%d ", no->e);
        printListReverse(no->prev);
    }
}

void sort_list(header_st *h)
{
    if (h->inicio == NULL)
        return;

    no_st* curr = h->inicio;
    while(curr != NULL){
        no_st* minNode = curr;
        no_st* temp = curr->prox;
        while(temp != NULL){
            if (temp->e < minNode->e)
                minNode = temp;
            temp = temp->prox;
        }
        Item tempData = curr->e;
        curr->e = minNode->e;
        minNode->e = tempData;
        curr = curr->prox;
    }
}

#define key(a) a
int insere_ordenado(header_st *h, Item e)
{
    if(h->inicio == NULL)
        return insere_depois(h, h->inicio, e);
    if(key(h->ultimo->e) <= key(e))
        return insere_depois(h, h->ultimo, e);
    no_st *aux = h->inicio;
    while(key(aux->e) <= key(e) && aux != NULL)
        aux = aux->prox;
    return insere_antes(h, aux, e);
}
