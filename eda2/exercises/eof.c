#include <stdio.h>

int main()
{
    int input, count=0;

    while(scanf("%d", &input) != EOF)
        count++;
    printf("%d\n", count);
}