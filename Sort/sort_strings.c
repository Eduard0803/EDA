#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NAME 30
#define key(a) a.name

typedef struct{
    char name[TAM_NAME];
    short int age;
}Item;

void sort_strings(Item *v, int l, int r)
{
    int i, m;   
    for(i=l; i<=r; i++){
        for(m=i+1; m<=r; m++){
           if(strcmp(key(v[i]), key(v[m])) > 0)
                exch(v[i], v[m]);
        }
    }
}
