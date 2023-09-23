// Node Pool
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
