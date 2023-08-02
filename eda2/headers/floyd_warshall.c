#define MAX_TAM 2010

int graph[MAX_TAM][MAX_TAM] = {0};
int dist[MAX_TAM][MAX_TAM] = {0};

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