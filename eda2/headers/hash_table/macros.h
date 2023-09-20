#define key(a) a.amount
#define eq(a, b) (key(a)==key(b))

typedef struct{
    char *name;
    int amount;
}Item;

typedef struct no_st{
    Item e;
    struct no_st *prox;
}no_st;

typedef struct{
    no_st *inicio;
    int size;
    no_st *ultimo;
}header_st;

typedef struct{
    int size, n_itens;
    header_st *table;
}hash_table;
