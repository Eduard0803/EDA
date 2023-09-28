#include <stdio.h>
#include <stdlib.h>
#define key(a) a
#define less(a, b) (key(a) < key(b))
#define T 1000010

int main(){
    int n, input, a=0;

    while(scanf("%d", &n), n != 0){
        int *v = (int*)calloc(T, sizeof(int));
        while(n--){
            scanf("%d", &input);
            if(++v[input] > v[a])
                a = input;
        }
        printf("%d\n", a);
        a=0;
    }
}
