#include <stdio.h>

void print_swap(char *str){
    if(str[0] == '\0')
        return;
    if(str[0] == 'x')
        printf("y");
    else
        printf("%c", str[0]);
    print_swap(&str[1]);
}

int main()
{
    char input[85];

    scanf(" %s", input);
    print_swap(&input[0]);
    printf("\n");
}