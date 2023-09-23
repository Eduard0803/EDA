typedef int Item; // define o tipo 'Item'
typedef enum {Red, Black}Color; // define o tipo 'Color'
typedef struct no_st{ // define o tipo 'no_st'
    Item data;
    struct no_st *right, *left; // ponteiros para os filhos da direita e esquerda
    Color color; // cor do link acima do 'node'
    int bumps; // contador para o número de colisões no 'node'
}no_st;
