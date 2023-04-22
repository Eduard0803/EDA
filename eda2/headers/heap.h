#include <stdio.h>
#include <stdlib.h>
/*
        Glossário
- Raiz é um dos Itens com a maior prioridade
- Folha é um dos Itens com a menor prioridade

        Regras
- A raiz fica no indice '1' do vetor
- Um filho não pode ter prioridade maior que seu pai
- Para encontrar o filho da esquerda, basta multiplicar o indice do pai por '2'
- Para encontrar o filho da direita, basta multiplicar o indice do pai por '2' e somar '1'
- Para encontrar o pai, basta dividir o indice do filho por '2'
*/
#define key(a) a
#define less(a, b) (key(a) < key(b)) // para trocar de maxHeap para minHeap basta trocar o sinal
#define exch(a, b) {Item t=a;a=b;b=t;}

typedef int Item;

static Item *heap;
static int last;

void heap_init(int max_tam){ // inicializa a heap
    heap =(Item *) malloc(sizeof(Item)*(max_tam+1)); // aloca um vetor com N+1 posições
    last = 1; // define o indice 1 como o proximo indice vazio
}

void fixUp(int k){ // conserta a heap de baixo para cima
    while(k > 1 && less(heap[k/2], heap[k])){ // enquanto não chegar na raiz e o filho for maior que seu pai
        exch(heap[k/2], heap[k]); // troca o filho com o pai
        k /= 2; // anda para o proximo pai
    }
}

void fixDown(int k, int lim){ // conserta a heap de cima para baixo
    while(2*k < lim){
        int j = 2*k;
        if(less(heap[j], heap[j+1]))
            j++;
        exch(heap[k], heap[j]);
        k = j;
    }
}

void heap_insert(Item novo){ // insere um novo Item na heap
    heap[last++] = novo;  // insere o Item na posição vazia e anda com o 'last'
    fixUp(last-1); // conserta a arvore de baixo para cima
}

Item heap_remove(){ // remove um dos elementos com a maior prioridade
    exch(heap[1], heap[last-1]); // troca a raiz com a ultima folha
    last--; // anda com o 'last'
    fixDown(1, last-1); // conserta a arvore de cima para baixo, para manter a ordem das prioridades
    return heap[last+1]; // retorna o Item que foi removido
}

int heap_empty(){ // retorna verdadeiro se ela estiver vazia
    return last == 1;
}

void heap_clean(){ // esvazia a heap
    last = 1;
}

void heap_print(){ // escreve a heap no console
    int i;
    for(i=1; i<last; ++i)
        printf("%d ", heap[i]);
    printf("\n");
}
