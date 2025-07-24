#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int v;
    int **matrix;

}Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->v= V;
    graph->matrix = (int **)malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)calloc(V,sizeof(int) );
    }
    return graph;
}
void addEdge(Graph *graph, int src , int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->v; i++) {
        for (int j = 0; j < graph->v; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

//duyet bang BFS
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enQueue(Queue *queue, int vertex) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = vertex;
}
int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}

int deQueue(Queue *queue) {
    if (!isEmpty(queue)) {
        int vertex = queue->arr[queue->front];
        queue->front ++;
        return vertex;
    }
    return -1;
}
void BFS(Graph *graph , int src ) {
    int *visited = (int *)calloc(graph->v, sizeof(int));
    Queue *queue = createQueue(graph->v);
    printf("cac dinh duoc duyet theo BFS tu %d:" , src);
    enQueue(queue, src);
    visited[src] = 1;
    while (!isEmpty(queue)) {
        int vertex = deQueue(queue);
        printf("%d ", vertex);
        for (int i = 0; i < graph->v; i++) {
            if (graph->matrix[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enQueue(queue, i);
            }
        }
    }
    printf("\n");
    free(queue->arr);
    free(queue);
    free(visited);

}
int main(void) {
    int v,e;
    printf("Enter the number of vertices and edge :\n");
    scanf("%d %d",&v,&e);
    Graph *graph = createGraph(v);
    printf("Enter the source vertex and destination vertex :\n");
    for (int i = 0; i < e; i++) {
        int src,dest;
        scanf("%d %d",&src,&dest);
        addEdge(graph, src, dest);
    }
    //printMatrix(graph);
    int start;
    printf("Enter the start vertex :\n");
    scanf("%d", &start);

    BFS(graph,start);
    return 0;
}