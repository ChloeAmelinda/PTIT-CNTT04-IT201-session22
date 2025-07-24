#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
}Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph *graph, int src , int dest) {

    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;

}
void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ",i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
//ham duyet dfs
void DFSUtil(Graph *graph , int src ,int *visited) {
    printf("%d ", src);
    visited[src] = 1;
    for (int i = 0; i < graph->V; i++) {
        if (graph->matrix[src][i] == 1 && visited[i] == 0) {
            DFSUtil(graph, i, visited);
        }
    }
}
void DFS(Graph *graph, int src) {
    int *visited = (int *)calloc(graph->V, sizeof(int));
    printf("Cac dinh duoc duyet theo  DSF tu dinh %d:",src);
    DFSUtil(graph, src, visited);
    printf("\n");
    free(visited);
}

int main(void) {
    int v,e;
    printf("enter the number of vertices and edge:");
    scanf("%d %d",&v , &e);


    Graph *graph = createGraph(v);
    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u,v;
        //printf("enter the edge from vertex %d to vertex %d:",i+1,i+1);
        scanf("%d %d",&u,&v);
        addEdge(graph, u, v);
    }
    int start;
    printf("enter the start vertex:");
    scanf("%d",&start);
    //printGraph(graph);
    DFS(graph, start);
    return 0;
}