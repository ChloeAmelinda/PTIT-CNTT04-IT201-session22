#include <stdio.h>

#define MAX 100

// Hàm thêm cạnh vào ma trận kề
void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // vì đồ thị là vô hướng
}
void printGraph(int graph[MAX][MAX] , int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5; // số đỉnh
    int graph[MAX][MAX] = {0} ; // khởi tạo ma trận với giá trị ban đầu là 0

    // Các cạnh cần thêm
   addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3,2);
    addEdge(graph, 1,3);
    addEdge(graph, 3,4);

    printGraph(graph,n);

    return 0;
}
