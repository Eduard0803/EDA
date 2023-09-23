## Códigos feitos durante as disciplinas [EDA-1](https://www.brunoribas.com.br/aed1/2022-2/) e [EDA-2](https://www.brunoribas.com.br/eda2/2023-1/)
Disciplinas: 'Estruturas de Dados e Algoritmos 1' e 'Estruturas de Dados e Algoritmos 2'  
Instituição: [Universidade de Brasília](https://international.unb.br/), [Faculdade do Gama](https://fga.unb.br/), [Engenharia de Software](http://software.unb.br)  
Prof. : [Dr. Bruno César Ribas](https://www.brunoribas.com.br/)  
[Apostila das diciplinas](https://www.brunoribas.com.br/apostila-eda/)  
[Benchmark-Ordenação](https://github.com/bcribas/benchmark-ordenacao)  

## EDA-1

### [Exercícios](eda1/exercises/) do [MOJ](https://moj.naquadah.com.br/)

### Header's
Contém os arquivos de cabeçalho (.h) com a implementação das estruturas de dados
- [Fila Dinâmica](eda1/Header's/dinamycQueue.h)
- [Pilha Dinâmica](eda1/Header's/dinamycStack.h)
- [Lista Encadeada](eda1/Header's/linkeed_list.h)
- [Fila Estática](eda1/Header's/queue.h)
- [Pilha Estática](eda1/Header's/stack.h)

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

## EDA-2

### [Exercícios](eda2/exercises/) do [MOJ](https://moj.naquadah.com.br/)

[Notas de aula grafos](eda2/Notas%20de%20Aula%20Graphs.pdf)

### [headers](eda2/headers/)
Contém os arquivos de cabeçalho (.h) com a implementação das estruturas de dados
- [quick_sort](eda2/headers/quick_sort.h) - Algoritmo de ordenação, complexidade variável O(N) - O(N²)
- [quick_select](eda2/headers/quick_select.h) - [Algoritmo de organização](https://www.youtube.com/watch?v=st8qo4RNS2I&pp=ygUYYnJ1bm8gcmliYXMgcXVpY2sgc2VsZWN0), complexidade variável O(N) - O(N²)
- [heap](eda2/headers/heap.h) - Fila de Prioridade na heap binária, complexidade O(logN) para todos os casos, exceto a remoção
- [hash_table](eda2/headers/hash_table/) - Implementação de uma tabela hash, complexidade entre O(1) e O(N) para todas as operações
- [node_pool](eda2/headers/node_pool.h) - Aloca uma piscina de nós para usar nas árvores
- [Binary_Search_Tree](eda2/headers/bst.h) - Árvore binária de busca simples, complexidade variavel, O(logN) e O(N) no melhor e pior caso  
- [red_Black](eda2/headers/Red_Black.h) - Árvore binária de busca auto-balanceada Red Black, complexidade O(logN) para todos os casos
- [floyd_warshall](eda2/headers/floyd_warshall.c) - Algoritmo Floyd Warshall para um grafo representado em uma matriz de adjacências, complexidade O(N³)  
