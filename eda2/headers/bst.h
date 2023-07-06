#include <stdio.h>
#include <stdlib.h>
#define key(a) a
#define less(a, b) (key(a) < key(b))

// - Binary Search Tree
// falta adicionar a função de remoção

typedef int Item; // define o tipo 'Item'
typedef struct no_st{ // define o tipo 'no_st'
    Item data;
    struct no_st *right, *left; // ponteiros para os filhos da direita e esquerda
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
    return toReturn;
}

void free_node(no_st *node){ // retorna um nó para a piscina
    node->right = pool_head;
    pool_head = node;
}

no_st *creat_node(Item data){ // cria um novo 'node'
    // no_st *novo_no = malloc(sizeof(no_st)); // aloca cada nó individualmente
    no_st *novo_no = get_free_node(); // pega um nó da piscina de nós
    novo_no->data = data;
    novo_no->right = NULL;
    novo_no->left = NULL;
    novo_no->bumps = 0;
    return novo_no;
}

no_st *insert(no_st *h, Item data){ // insere um Item na ávore e retorna a raiz
    if(h == NULL) // se a árvore estiver vazia cria o 'node' e o retorna como raiz
        return creat_node(data);

    if(less(data, h->data)) // data less than h->data
        h->left = insert(h->left, data);
    else if(less(h->data, data)) // data greater than h->data
        h->right = insert(h->right, data);
    else // data equals to h->data
        // h->data = data; // atualiaza o Item
        h->bumps++; // incrementa no contador de colisões
    return h;
}

void in_order(no_st *h){ // crossing 'in order'
    int count = 0;
    if(h == NULL)
        return;
    in_order(h->left);
    while(count++ <= h->bumps) // imprime a quantidade de colisóes que tiver no 'node'
        printf("%d ", key(h->data));
    in_order(h->right);
}

no_st* search(no_st *h, Item data){ // busca de dados na árvore
    if(h == NULL) // retorna 'NULL' se a árvore estiver vazia ou não encontrar o 'node'
        return NULL;
    if(less(data, h->data))
        return search(h->left, data);
    if(less(h->data, data))
        return search(h->right, data);
    return h; // senão retorna o 'node'
}
