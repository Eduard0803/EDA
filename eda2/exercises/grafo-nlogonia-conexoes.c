#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 2010
// Estradas asfaltadas - perguntando conexões
int graph[MAX_TAM][MAX_TAM] = {0};
int dist[MAX_TAM][MAX_TAM] = {0};
void Floyd_Warshall(int V);

int main()
{
    int V, v=1, w=1, d=1, op;

    scanf("%d", &V);
    while(v != 0 || w != 0 || d != 0){
        scanf("%d %d %d", &v, &w, &d);
        if(d == 2){
            graph[v][w] = 1;
            graph[w][v] = 1;
        }
        else if(d == 1)
            graph[v][w] = 1;
    }
    Floyd_Warshall(V);

    // printf("\n\t\tGraph\n\n");

    // for(int i=0; i<V; ++i){
    //     for(int j=0; j<V; ++j)
    //         printf("%d ", dist[i][j]);
    //     printf("\n");
    // }
    // return 0;

    while(scanf("%d %d", &v, &w) != EOF)
    {
        if(dist[v][w] && dist[w][v])
            printf("Ida e Volta\n");
        else if(dist[v][w])
            printf("Apenas Ida\n");
        else if(dist[w][v])
            printf("Apenas Volta\n");
        else
            printf("Impossibru\n");
    }
}

void Floyd_Warshall(int V){
    for(int i=0; i<V; ++i)
        for(int j=0; j<V; ++j)
            dist[i][j] = graph[i][j];

    for(int i=0; i<V; ++i)
        dist[i][i] = 1;
    
    for(int i=0; i<V; ++i)
        for(int s=0; s<V; ++s){
            if(dist[s][i])
            for(int t=0; t<V; ++t)
                if(dist[i][t])
                    dist[s][t] = 1;
        }
}
