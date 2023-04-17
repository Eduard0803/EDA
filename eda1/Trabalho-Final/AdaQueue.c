#include <stdio.h>
#include <stdlib.h>
#define ADA "No job for Ada?\n"

typedef long int Item; // define o tipo 'Item' como um inteiro

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

int main()
{
    header_st *h = malloc(sizeof(header_st));
    char *input = malloc(sizeof(char)*21);
    Item buffer;
    long int n_requests;
    int flag=0;

    scanf("%ld", &n_requests);

    while(n_requests)
    {
        scanf(" %s", input);
        if(input[0] == 'b'){
            if(empty(h))
                printf(ADA);
            else if(flag % 2 == 0){
                printf("%ld\n", h->ultimo->e);
                remove_ultimo(h);
            }
            else{
                printf("%ld\n", h->inicio->e);
                remove_inicio(h);
            }
        }
        else if(input[0] == 'f'){
            if(empty(h))
                printf(ADA);
            else if(flag % 2 == 0){
                printf("%ld\n", h->inicio->e);
                remove_inicio(h);
            }
            else{
                printf("%ld\n", h->ultimo->e);
                remove_ultimo(h);
            }
        }
        else if(input[0] == 'r')
            flag++;
        else if(input[0] == 'p'){
            scanf("%ld", &buffer);
            if(flag % 2 == 0)
                insere_depois(h, h->ultimo, buffer);
            else
                insere_antes(h, h->inicio, buffer);
        }
        else if(input[0] == 't'){
            scanf("%ld", &buffer);
            if(flag % 2 == 0)
                insere_antes(h, h->inicio, buffer);
            else
                insere_depois(h, h->ultimo, buffer);
        }
        n_requests--;
    }
    free(input);
    free(h);
    return 0;
}

/*

back - Print number from back and then erase it
front - Print number from front and then erase it
reverse - Reverses all elements in queue
push_back N - Add element N to back
toFront N - Put element N to front

15 toFront 93 front back reverse back reverse toFront 80 push_back 53 push_back 50 front front reverse push_back 66 reverse front

*/
