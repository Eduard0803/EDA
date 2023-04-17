#include <stdio.h>
#include <stdlib.h>

#define key(a) a.score
#define less(a, b) (key(a) < key(b))

typedef struct{
    int id, score;
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

Item v[200];

int main()
{
    int n_cases, i, day=0;

    while(scanf("%d", &n_cases) != EOF){

        for(i=0; i<n_cases; i++)
            scanf("%d %d", &v[i].id, &v[i].score);
        
        merge_sort(v, 0, n_cases-1);

        i = n_cases-1;
        int cloud_score=v[i].score, less_id=v[i].id;

        while(v[i].score == cloud_score && i>=0){
            if(v[i].id < less_id)
                less_id = v[i].id;
            i--;
        }

        printf("Dia %d\n%d\n\n", ++day, less_id);
    }
}
