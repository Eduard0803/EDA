#include <stdio.h>
#include <stdlib.h>
#include "macros.h"

#define SIZE 71
#define HASH(a) (key(a)%SIZE)

void hash_init(hash_table *ht){
    ht->table = malloc(sizeof(header_st)*SIZE);
    ht->size = 0;
    ht->n_itens = 0;

    for(int i=0; i<SIZE; ++i){
        ht->table[i].inicio = NULL;
        ht->table[i].size = 0;
    }
}

int hash_empty(hash_table *ht){return ht->n_itens == 0;}
void hash_insert(hash_table *ht, Item e){
    no_st *novo_no = malloc(sizeof(no_st));
    novo_no->e = e;
    ++ht->table[HASH(e)].size;
    ++ht->n_itens;
    novo_no->prox = ht->table[HASH(e)].inicio;
    ht->table[HASH(e)].inicio = novo_no;
}

void hash_remove(hash_table *ht, Item e){
    no_st *aux = ht->table[HASH(e)].inicio, *trash = ht->table[HASH(e)].inicio->prox;

    --ht->table[HASH(e)].size;
    --ht->n_itens;
    if(eq(aux->e, e)){
        ht->table[HASH(e)].inicio = aux->prox;
        free(aux);
        return;
    }
    while(trash != NULL && !eq(trash->e, e)){
        aux = trash;
        trash = trash->prox;
    }
    aux->prox = trash->prox;
    free(trash);
}

no_st* hash_search(hash_table *ht, Item e){
    no_st *aux = ht->table[HASH(e)].inicio;
    
    while(!eq(aux->e, e) && aux != NULL)
        aux = aux->prox;

    return eq(aux->e, e) ? aux : NULL;
}
