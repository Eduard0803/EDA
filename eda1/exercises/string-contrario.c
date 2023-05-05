#include <stdio.h>

void print_reverse(char *str){
    if(str[0] == '\0')
        return;
    print_reverse(&str[1]);
    printf("%c", str[0]);
}

int main()
{
    char input[510];

    scanf(" %s", input);
    print_reverse(&input[0]);
    printf("\n");
}