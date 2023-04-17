#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(a) a.score
#define less(a, b) (key(a) >= key(b))

typedef struct{
    char name[25];
    int score;
}Item;

void merge(Item *v, int l, int m, int r)
{
    Item *p = malloc(sizeof(Item) * (r-l+1));
    int ia=l, ib=m+1, iaux=0, i;

    while(ia <= m && ib <= r)
    {
        if(less(v[ia], v[ib]))
            p[iaux++] = v[ia++];
        else
            p[iaux++] = v[ib++];
    }
    while(ia <= m)
        p[iaux++] = v[ia++];
    while(ib <= r)
        p[iaux++] = v[ib++];

    iaux = 0;
    for(i=l; i<=r; i++)
        v[i] = p[iaux++];
    free(p);
}

void merge_sort(Item *v, int l, int r)
{
    if(r-l == 0)
        return;
    int m = (r+l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

Item v[100];

int main()
{
    int n_cases, i, instancia=0;

    while(scanf("%d", &n_cases) != EOF){

        for(i=0; i<n_cases; i++)
            scanf(" %s %d", v[i].name, &v[i].score);
        merge_sort(v, 0, n_cases-1);
        
        char *cloud_name=v[n_cases-1].name;
        int less_score=v[n_cases-1].score;
        i = n_cases-2;

        while(v[i].score == less_score){
            if(strcmp(cloud_name, v[i].name) < 0)
                cloud_name = v[i].name;
            i--;
        }
        printf("Instancia %d\n%s\n\n", ++instancia, cloud_name);
    }
}
