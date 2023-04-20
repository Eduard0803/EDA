#include <stdio.h>
#include <stdlib.h>

#define key(a) a
#define less(a, b) (key(a) < key(b)) // para trocar de maxHeap para minHeap basta trocar o sinal
#define exch(a, b) {Item t=a;a=b;b=t;}
#define MAX_TAM 100

typedef int Item;

static Item *heap;
static int last;

void heap_init(int max_tam) // inicializa a heap
{
    heap = malloc(sizeof(Item)*(max_tam+1));
    last = 1;
}

void fixUp(int k) // conserta a heap
{
    while(k > 1)
        if(less(heap[k/2], heap[k])){
            exch(heap[k/2], heap[k]);
            k /= 2;
        }
        else
            break;
}

void fixDown(int k, int lim) // conserta a heap
{
    while(2*k < lim){
        int j = 2*k;
        if(less(heap[j], heap[j+1]))
            j++;
        exch(heap[k], heap[j]);
        k = j;
    }
}

void heap_insert(Item novo) // insere um novo elemto na heap
{
    heap[last++] = novo;
    fixUp(last-1);
}

Item heap_remove() // remove o elemento com a maior prioridade
{
    exch(heap[1], heap[last-1]);
    last--;
    fixDown(1, last-1);
    return heap[last+1];
}

int heap_empty() // retorna verdadeiro se ela estiver vazia
{
    return last == 1;
}

void heap_clean() // esvazia a heap
{
    last = 1;
}

void heap_print() // escreve a heap no console
{
    int i;
    for(i=1; i<last; ++i)
        printf("%d ", heap[i]);
    printf("\n");
}
