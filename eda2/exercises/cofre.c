#include <stdio.h>

int main()
{
    int count=1, j=0, z=0, sum=0, test=0;

    while(1)
    {
        scanf("%d", &count);
        if(count == 0)break;
        printf("Teste %d\n", ++test);
        while(count--){
            scanf("%d %d", &j, &z);
            j -= z;
            sum += j;
            printf("%d\n", sum);
        }
        sum=0;
        printf("\n");
    }
}