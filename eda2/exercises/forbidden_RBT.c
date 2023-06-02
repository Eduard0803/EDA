#include <stdio.h>
#include <stdlib.h>
#define key(a) a
#define less(a, b) (key(a) < key(b))

typedef int Item; // define o tipo 'Item'
typedef enum {Red, Black}Color; // define o tipo 'Color'
typedef struct no_st{ // define o tipo 'no_st'
    Item data;
    struct no_st *right, *left; // ponteiros para os filhos da direita e esquerda
    Color color; // cor do link acima do 'node'
    int bumps; // contador para o número de colisões no 'node'
}no_st;

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

no_st *pool_head = NULL; // no cabeça para a piscina de nós
int empty_pool(){ return pool_head == NULL ? 1 : 0;} // retorna 'true' se e piscina estiver vazia, senão 'false'
int grow_pool(int n) // cria a piscina de nós
{
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

no_st* get_free_node() // retorna um nó para uso
{
    no_st *toReturn = pool_head;
    pool_head = pool_head->right;
    // toReturn->color = Red;
    // toReturn->bumps = 0;
    // toReturn->right = NULL;
    // toReturn->left = NULL;
    return toReturn;
}

void free_node(no_st *node) // retorna um nó para a piscina
{
    node->right = pool_head;
    pool_head = node;
}

no_st *creat_node(Item data){ // cria um novo 'node'
    // no_st *novo_no = malloc(sizeof(no_st)); // aloca cada nó individualmente
    no_st *novo_no = get_free_node(); // pega um nó da piscina de nós
    novo_no->color = Red;
    novo_no->data = data;
    novo_no->right = NULL;
    novo_no->left = NULL;
    novo_no->bumps = 0;
    return novo_no;
}

#define isRed(a) ((a) && a->color == Red) // return true if the link is 'Red' otherwise false
// int isRed(no_st *h){if(h == NULL) return 0; return h->color == Red ? 1 : 0;}

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
    
    if(isRed(h->right) && !isRed(h->left)) // If it has a 'RED' link on the right
        h = rotate_left(h);
    if(isRed(h->left) && isRed(h->left->left)) // If it has a two consecutive 'RED' links
        h = rotate_right(h);
    if(isRed(h->left) && isRed(h->right)) // If a node has a both 'RED' links
        flip_colors(h);
    return h;
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

#define test(a) printf("test\n")
int main()
{
    grow_pool(150000);
    no_st *root = malloc(sizeof(no_st));
    int n, first, input, r;

    r=scanf("%d %d", &n, &first);
    root = insert(NULL, first);

    while(--n){
        r=scanf("%d", &input);
        root = insert(root, input);
    }

    while(scanf("%d", &input) != EOF){
        no_st *buffer = search(root, input);
        printf(buffer == NULL ? "nao\n" : "sim\n");
    }
}
