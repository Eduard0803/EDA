#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int Item; // define o tipo 'Item' como um inteiro

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

int inicializa_lista(header_st *h);
int empty(header_st *h);
int insere_depois(header_st *h, no_st *no, Item e);
int insere_antes(header_st *h, no_st *no, Item e);
int insere_ordenado(header_st *h, Item e);
void remove_ultimo(header_st *h);
void imprime_n_Itens(header_st *h, int n_itens);

int main()
{
    header_st *h = malloc(sizeof(header_st));
    Item input, buffer;
    int choose, ind=0, n_itens;

    inicializa_lista(h);

    while(scanf("%d", &choose) != EOF)
    {
        if(choose == 1)
        {
            if(h->size == 100)
                buffer = h->ultimo->e;
            scanf("%lld", &input);
            if(ind < 100){
                insere_ordenado(h, input);
                ind++;
            }
            else if(input < buffer){
                insere_ordenado(h, input);
                remove_ultimo(h);
                buffer = h->ultimo->e;
            }
        }
        else if(choose == 2){
            scanf("%d", &n_itens);
            imprime_n_Itens(h, n_itens);
            printf("\n");
        }
    }
}

/*
1 1365271 1 9164517 1 5782846 2 2 1 1153896 1 3641547 2 2

1365271 5782846
1153896 1365271


1 9019747 1 3629786 1 7091927 2 1 1 2013733 1 4784225 1 7865835 1 7145336 1 3536931 1 9584045 1 1967593 2 7

3629786
1967593 2013733 3536931 3629786 4784225 7091927 7145336
*/

void imprime_n_Itens(header_st *h, int n_itens)
{
    if(n_itens == 0) return;
    no_st *aux = h->inicio;
    printf("%lld", aux->e);
    aux = aux->prox;
    for(int i=1; i<n_itens; i++){
        printf("% lld", aux->e);
        aux = aux->prox;
    }
}

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

int insere_ordenado(header_st *h, Item e) // insere os elementos na lista, já de forma ordenada
{
    if(h->inicio == NULL)
        return insere_depois(h, h->inicio, e);
    if(h->ultimo->e <= e)
        return insere_depois(h, h->ultimo, e);
    no_st *aux = h->inicio;
    while(aux->e <= e && aux != NULL)
        aux = aux->prox;
    return insere_antes(h, aux, e);
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
