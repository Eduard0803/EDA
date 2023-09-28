#include <stdio.h>
#include <stdlib.h>
#define T 1<<20

int main(){
    char input, *v = calloc((T)*4, sizeof(char));
    int i, f, l=T;

    scanf("%d %c", &f, &input);
    v[(T)] = input;

    while(scanf("%d %c", &i, &input) != EOF){
        v[(T)-(f-i)] = input;
        if(l > (T)-(f-i))
            l = (T)-(f-i);
    }
    for(int k=l; v[k]!=0; ++k)
        printf("%c", v[k]);
    printf("\n");
}
