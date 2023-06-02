#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAM.h"

int main()
{
    srand(time(NULL));

    for(int i=0; i<N; ++i)
        printf("%c\n", rand()%26+65);
}
