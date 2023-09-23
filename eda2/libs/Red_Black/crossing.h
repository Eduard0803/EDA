#include <stdio.h>
#define key(a) a

// crossing
void in_order(no_st *h){ // transverse 'in-order'
    int count = 0;
    if(h == NULL)
        return;
    in_order(h->left);
    while(count++ <= h->bumps)
        printf("%d ", key(h->data));
    in_order(h->right);
}

void pre_order(no_st *h){ // transverse 'pre-order'
    int count = 0;
    if(h == NULL)
        return;
    while(count++ <= h->bumps)
        printf("%d ", key(h->data));
    pre_order(h->left);
    pre_order(h->right);
}

void pos_order(no_st *h){ // transverse 'pos-order'
    int count = 0;
    if(h == NULL)
        return;
    pos_order(h->left);
    pos_order(h->right);
    while(count++ <= h->bumps)
        printf("%d ", key(h->data));
}
