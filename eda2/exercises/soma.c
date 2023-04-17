#include <stdio.h>

int main()
{
    int count, input, sum=0;

    scanf("%d", &count);

    while(count--){
        scanf("%d", &input);
        sum += input;
    }
    printf("%d\n", sum);
}