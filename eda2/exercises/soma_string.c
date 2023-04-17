#include <stdio.h>

int main()
{
    int count, out=0, i=0;
    char input[101];
    
    scanf("%d", &count);
    
    while(count--)
    {
        scanf(" %s", input);
        while(input[i] != '\0')
        {
            if(input[i] >= '0' && input[i] <= '9')
                out += input[i] - 48;
            i++;
        }
        printf("%d\n", out);
        out=0;i=0;
    }
}