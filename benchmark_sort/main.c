#include <stdio.h>
#include <stdlib.h>
#include "TAM.h"
/*
        command line
 - gcc -w -O2 -Dinsertionsort -o main main.c
 - time ./main < input
*/

void error(){
        printf("Error\n");
        exit(0);
}
int main()
{
        #ifdef redblack
                #include "Red_Black.h"

                char input;
                no_st *root = malloc(sizeof(no_st));
                root = insert(NULL, 1);
                        
                for(int i=0; i<N; ++i){
                        scanf("%c", &input);
                        root = insert(root, input);
                }
                in_order(root);
                exit(0);

        #elif bubblesort
                #include "bubble_sort.h"
                #define sort(a, b, c) bubble_sort(a, b, c)
        #elif selectionsort
                #include "selection_sort.h"
                #define sort(a, b, c) selection_sort(a, b, c)
        #elif insertionsort
                #include "insertion_sort.h"
                #define sort(a, b, c) insertion_sort(a, b, c)
        #elif mergesort
                #include "merge_sort.h"
                #define sort(a, b, c) merge_sort(a, b, c)
        #elif quicksort
                #include "quick_sort.h"
                #define sort(a, b, c) quick_sort(a, b, c)
        #else
                error();
        #endif

        char v[N];

        for(int i=0; i<N; ++i)
                scanf("%c", &v[i]);

        sort(v, 0, N-1);
}
