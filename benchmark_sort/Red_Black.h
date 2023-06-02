#include <stdlib.h>
#include "macros.h"

typedef enum {Red, Black}Color;
typedef struct no_st{
    Item data;
    struct no_st *right, *left;
    Color color;
    int bumps;
}no_st;

no_st* rotate_left(no_st *h){
    no_st *x = h->right;
    h->right = x->left;
    x->left = h;
    h->color = Red;
    x->color = Black;
    return x;
}

no_st* rotate_right(no_st *h){
    no_st *x = h->left;
    h->left = x->right;
    x->right = h;
    h->color = Red;
    x->color = Black;
    return x;
}

void flip_colors(no_st *h){
    h->right->color = Black;
    h->left->color = Black;
    h->color = Red;
}

no_st *creat_node(Item data){
    no_st *novo_no = malloc(sizeof(no_st));
    novo_no->color = Red;
    novo_no->data = data;
    novo_no->right = NULL;
    novo_no->left = NULL;
    novo_no->bumps = 0;
    return novo_no;
}

#define isRed(a) ((a) && a->color == Red)

no_st *insert(no_st *h, Item data){
    if(h == NULL)
        return creat_node(data);

    if(less(data, h->data))
        h->left = insert(h->left, data);
    else if(less(h->data, data))
        h->right = insert(h->right, data);
    else
        h->bumps++;
    
    if(isRed(h->right) && !isRed(h->left))
        h = rotate_left(h);
    if(isRed(h->left) && isRed(h->left->left))
        h = rotate_right(h);
    if(isRed(h->left) && isRed(h->right))
        flip_colors(h);
    return h;
}

void in_order(no_st *h){
    int count = 0;
    if(h == NULL)
        return;
    in_order(h->left);
    while(count++ <= h->bumps);
    in_order(h->right);
}
