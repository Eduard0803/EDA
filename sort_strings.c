#include <stdio.h>
#include <string.h>

#define TAM_L 3
#define TAM_C 20

char str[TAM_L][TAM_C];

void sort_strings();

int main()
{
    int i;
    
    for(i=0; i<TAM_L; i++){
        printf("Digite a string: ");
        scanf(" %s", str[i]);
    }

    sort_strings();
    
    for(i=0; i<TAM_L; i++){
        printf("str[i]: %s\n", str[i]);
    }
}

void sort_strings()
{
    char aux[TAM_C];
    int i, m, r;
    
    for(i=0; i<TAM_L; i++){
        for(m=i+1; m<TAM_L; m++){
           r = strcmp(str[i], str[m]);
           if(r > 0){
                strcpy(aux, str[i]);
                strcpy(str[i], str[m]);
                strcpy(str[m], aux);
           }
        }
    }
}