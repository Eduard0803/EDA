#include "types.h"
#include "node_pool.h"
#include "balance.h"
#include "crossing.h"

/*
    - Red Black Tree

    'Red Black' is a way to represent the '2-3-4 Tree' em uma 'Binary Tree'
    
    - Rules
        - 'RED' links will always be on the left
        - Cannot have two consecutive 'RED' links 
        - The amount of 'Black' links is the same between the root and any of the leaves
        - The Red-Black Tree does not admit collisions

    - Error Treatment
        - If it has a 'RED' link on the right, rotate_left
        - If it has a two consecutive 'RED' links, rotate_right
        - If a node has a both 'RED' links, flip_colors
*/

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
    
    return balance(h);
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
