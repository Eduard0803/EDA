#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#define SIZE 71 // constante para definir o tamanho da tabela
#define HASH(a) (key(a)%SIZE) // macro para calcular o Hash

void hash_init(hash_table *ht){ // inicializa a tabela hash
    ht->table = malloc(sizeof(header_st)*SIZE);
    ht->size = SIZE;
    ht->n_itens = 0;

    for(int i=0; i<SIZE; ++i){
        ht->table[i].inicio = NULL;
        ht->table[i].size = 0;
    }
}

int hash_empty(hash_table *ht){return ht->n_itens == 0;} // retorna se ela está vazia
void hash_insert(hash_table *ht, Item e){ // insere um Item na tabela
    no_st *aux = ht->table[HASH(e)].inicio;
    while(aux != NULL && !eq(aux->e, e))
        aux = aux->prox;
    if(aux != NULL){
        aux->e = e; // atualiza o Item se houver repetição de chaves
        return;
    }
    no_st *novo_no = malloc(sizeof(no_st));
    novo_no->e = e;
    ++ht->table[HASH(e)].size;
    ++ht->n_itens;
    novo_no->prox = ht->table[HASH(e)].inicio;
    ht->table[HASH(e)].inicio = novo_no;
}

void hash_remove(hash_table *ht, Item e){ // remove um Item da tabela
    no_st *aux = ht->table[HASH(e)].inicio, *trash = ht->table[HASH(e)].inicio->prox;

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

Item* hash_search(hash_table *ht, Item e){ // faz a busca e retorna um Item da tabela
    no_st *aux = ht->table[HASH(e)].inicio;
    
    while(aux != NULL && !eq(aux->e, e))
        aux = aux->prox;

    return aux != NULL ? &aux->e : NULL;
}

int hash_find(hash_table *ht, Item e){ // retorna se o Item existe na tabela
    no_st *aux = ht->table[HASH(e)].inicio;
    
    while(aux != NULL && !eq(aux->e, e))
        aux = aux->prox;

    return aux != NULL ? 1 : 0;
}
