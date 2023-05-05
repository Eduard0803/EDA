#include <stdio.h>
#include <stdlib.h>

void sum_digit(char *p){
    static int sum = 0;
    if(*p == '\0'){
        printf("%d\n", sum);
        return;
    }
    sum += (*p-48);
    sum_digit(&p[1]);
}

int main(){
    char number[15];

    scanf(" %s", number);
    sum_digit(&number[0]);
}
