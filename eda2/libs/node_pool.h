#include <stdlib.h>

typedef int Item; // define o tipo 'Item'
typedef enum {Red, Black}Color; // define o tipo 'Color'
typedef struct no_st{ // define o tipo 'no_st'
    Item data;
    struct no_st *right, *left; // ponteiros para os filhos da direita e esquerda
    Color color; // cor do link acima do 'node'
    int bumps; // contador para o número de colisões no 'node'
}no_st;

no_st *pool_head = NULL; // no cabeça para a piscina de nós
int empty_pool(){ return pool_head == NULL ? 1 : 0;} // retorna 'true' se e piscina estiver vazia, senão 'false'
int grow_pool(int n){ // cria a piscina de nós
    no_st *novo_no = malloc(sizeof(no_st)*n);
    if(novo_no == NULL)
        return 0;
    
    n--;
    for(int i=0; i<n; ++i)
        novo_no[i].right = &novo_no[i+1];
    novo_no[n].right = pool_head;
    pool_head = novo_no;
    return 1;
}

no_st* get_free_node(){ // retorna um nó para uso
    no_st *toReturn = pool_head;
    pool_head = pool_head->right;
    // toReturn->color = Red;
    // toReturn->bumps = 0;
    // toReturn->right = NULL;
    // toReturn->left = NULL;
    return toReturn;
}

void free_node(no_st *node){ // retorna um nó para a piscina
    node->right = pool_head;
    pool_head = node;
}
