#include <stdio.h>

int count = 0;
void count_pair(char *str){
    if(str[2] == '\0')
        return;
    if(str[0] == str[2])
        count++;
    count_pair(&str[1]);
}

int main()
{
    char input[210];

    scanf(" %s", input);
    count_pair(&input[0]);
    printf("%d\n", count);
}
