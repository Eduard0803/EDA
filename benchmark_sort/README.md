## BenchMark Sort

Prototipo de benchmark para os algoritmos de ordenação  

## Algoritmos usados

| Algoritmo | Complexidade |
| --------- | ------------ |
| [bubblesort](bubble_sort.h) | O(n²) |
| [selectionsort](selection_sort.h) | O(n²) |
| [insertionsort](insertion_sort.h) | O(n) - O(n²) |
| [mergesort](merge_sort.h) | O(logN) |
| [quicksort](quick_sort.h) | O(n) - O(n²) |
| [redblack](Red_Black.h) | O(logN) |

## Testes

Para excutar o script clone o repositório com o comando  
`git clone https://github.com/Edaurd0803/EDA/`  

Navegue até o diretório do BenchMark  
`cd BenchMark`  

Com o instalado execute os comandos:  
`gcc -o main creat_input.c`  
`./main > input`  
`gcc -w -O2 -Dalgorithm_name -o main main.c`  
`time ./main < input`  

A saída esperada é o tempo de execução dos algoritmos  

No lugar de `algorithm_name` coloque o nome do algoritmo  
Exemplo:  
 - `gcc -w -O2 -Dmergesort -o main main.c`  

O comando acima irá executar o 'merge_sort'  
