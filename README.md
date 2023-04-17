# Códigos feitos durante as disciplinas [EDA-1](https://www.brunoribas.com.br/aed1/2022-2/) e [EDA-2](https://www.brunoribas.com.br/eda2/2023-1/)
Disciplinas: 'Estruturas de Dados e Algoritmos 1' e 'Estruturas de Dados e Algoritmos 2'  
Instituição: [Universidade de Brasília](https://international.unb.br/), [Faculdade do Gama](https://fga.unb.br/), [Engenharia de Software](http://software.unb.br)  
Prof. : [Dr. Bruno César Ribas](https://www.brunoribas.com.br/)  

# EDA-1

### Header's
Contém os arquivos de cabeçalho (.h) com a implementação das estruturas de dados  
- [dinamycQueue](eda1/Header's/dinamycQueue.h) - Fila Dinâmica
    - `inicializa_fila` - recebe um ponteiro do tipo `fila_st` e inicializa seus itens
    - `enfila` - recebe um ponteiro do tipo `fila_st` e um `Item`, se a fila estiver vazia insere o `Item` no inicio da fila, senão o insere no final da fila
    - `desenfila` - recebe um ponteiro do tipo `fila_st`, remove o ultimo `Item` da fila e o retorna
    - `espia` - recebe um ponteiro do tipo `fila_st` e retorna o `Item` que está no inicio da fila
    - `empty` - recebe um ponteiro do tipo `fila_st` e retorna verdadeiro se a fila estiver vazia, senão retorna falso
    - `imprime_fila` - recebe um ponteiro do tipo `no_st` e o imprime no console com todos os outros nós até o final da fila
    - `imprime_fila_in_file` - recebe o nome de um arquivo e um ponteiro do tipo `no_st` e o imprime no arquivo com todos os outros nós até o final da fila
    - `inverte_fila` - recebe um ponteiro do tipo `fila_st` e inverte a fila
- [dinamycStack](eda1/Header's/dinamycStack.h) - Pilha Dinâmica
    - `inicializa_stack` - recebe um ponteiro do tipo `stack_st` e inicializa seus itens
    - `empilha` - recebe um ponteiro do tipo `stack_st` e um `Item` e o insere no topo da pilha
    - `desempilha` - recebe um ponteiro do tipo `stack_st`, remove o `Item` do topo e o retorna
    - `topo` - recebe um ponteiro do tipo `stack_st` e retorna o `Item` que está no topo da pilha 
    - `esta_vazia` - recebe um ponteiro do tipo `stack_st` e retorna verdadeiro se a pilha estiver vazia, senão retorna falso
- [double_linkeed](eda1/Header's/double_linkeed.h) - Lista Duplamente Encadeada
    - `inicializa_lista` - recebe um ponteiro do tipo `header_st` e inicializa seus itens
    - `empty` - recebe um ponteiro do tipo `header_st` e retorna verdadeiro se a lista estiver vazia, senão retorna falso
    - `insere_depois` - recebe ponteiros do tipo `header_st` e `no_st` e um `Item` e o insere depois do nó, em caso de sucesso retorna 1, caso contrario, retorna 0
    - `insere_antes` - recebe ponteiros do tipo `header_st` e `no_st` e um `Item` e o insere antes do nó, em caso de sucesso retorna 1, caso contrario, retorna 0
    - `remove_inicio` - recebe um ponteiro do tipo `header_st` e remove o `Item` que está no inicio da lista
    - `remove_ultimo` - recebe um ponteiro do tipo `header_st` e remove o `Item` que está no final da lista
    - `reverseList` - recebe um ponteiro do tipo `header_st` e inverte a lista
    - `printList` - recebe um ponteiro do tipo `no_st` e o imprime no console com todos os outros nós após ele, até o final da lista
    - `printListReverse` - recebe um ponteiro do tipo `no_st` e o imprime no console com todos os outros nós anteriores à ele, até o inicio da lista
    - `sort_list` - recebe um ponteiro do tipo `header_st` e ordena a lista com o algoritmo `selection sort`, complexidade constante O(N²) 
    - `insere_ordenado` - recebe um ponteiro do tipo `header_st` e um `Item` e o insere na fila, respeitando a ordenação das chaves, ideal para a `priorityQueue`
- [linkeed_list](eda1/Header's/linkeed_list.h) - Lista Encadeada
- [queue](eda1/Header's/queue.h) - Fila Estática
- [stack](eda1/Header's/stack.h) - Pilha Estática

### Sort
Contém os algoritmos de busca e ordenação de dados  
- [binary_search.c](eda1/Sort/binary_search.h) - algoritmo de busca binária, complexidade variável O(1) - O(logN)
- [bubble_sort.c](eda1/Sort/bubble_sort.h) - algoritmo de ordenação por bolha, complexidade constante O(N²)
- [insertion_sort.c](eda1/Sort/insertion_sort.h) - algoritmo de ordenação por inserção, complexidade variável O(N) - O(N²)
- [macros_para_ordenação](eda1/Sort/macros_para_ordenação.h) - contém as macros utilizadas nos algoritmos de busca e ordenação
- [merge2](eda1/Sort/merge2.h) - realiza a operação do 'merge' com dois vetores distintos
- [merge_delete_pivo](eda1/Sort/merge_delete_pivo.h) - realiza a operação do 'merge', mas apagando o pivo no vetor resultante
- [merge_sort](eda1/Sort/merge_sort.h) - algoritmo de ordenação 'merge sort', complexidade constante O(N*logN)
- [selection_sort](eda1/Sort/selection_sort.h) - algoritmo de ordenação 'selection sort', complexidade constante O(N²)

### Trabalho Final
Contém as [soluções](eda1/Trabalho-Final/) de alguns problemas feitos para o trabalho final da disciplina  
- os problemas estão em formato (.pdf) e as resoluções em formato (.c)

# [EDA-2](https://www.brunoribas.com.br/eda2/2023-1/)

### [Exercícios](eda2/exercises/) de EDA-2 no sistema [MOJ - Meta Online Judge](https://moj.naquadah.com.br/)

Contém as soluções de alguns exercicios durante a disciplina  
- os problemas estão em formato (.pdf) e as resoluções em formato (.c)
