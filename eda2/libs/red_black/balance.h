#define key(a) a
#define less(a, b) (key(a) < key(b))
#define isRed(a) ((a) && a->color == Red) // return true if the link is 'Red' otherwise false
// int isRed(no_st *h){if(h == NULL) return 0; return h->color == Red ? 1 : 0;}
int max(int a, int b){return a>b ? a : b;} // return the greater number
int min(int a, int b){return a<b ? a : b;} // return the less number

no_st* rotate_left(no_st *h){ // quando tem um filho 'RED' na direita
    no_st *x = h->right;
    h->right = x->left;
    x->left = h;
    h->color = Red;
    x->color = Black;
    return x;
}

no_st* rotate_right(no_st *h){ // quando tem dois filhos 'RED' um seguido do outro
    no_st *x = h->left;
    h->left = x->right;
    x->right = h;
    h->color = Red;
    x->color = Black;
    return x;
}

void flip_colors(no_st *h){ // quando os dois filhos são 'Red' e o pai e 'Black'
    h->right->color = Black;
    h->left->color = Black;
    h->color = Red;
}

no_st* balance(no_st *h){
    if(isRed(h->right) && !isRed(h->left)) // If it has a 'RED' link on the right
        h = rotate_left(h);
    if(isRed(h->left) && isRed(h->left->left)) // If it has a two consecutive 'RED' links
        h = rotate_right(h);
    if(isRed(h->left) && isRed(h->right)) // If a node has a both 'RED' links
        flip_colors(h);
    return h;
}
