#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút trong danh sách kề
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo một nút mới
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cạnh giữa hai đỉnh
void addEdge(Node* adjList[], int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

// Hàm in ra danh sách kề
void printAdjList(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    Node* adjList[n]; // Mảng danh sách kề cho n đỉnh

    // Khởi tạo danh sách rỗng
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    // Thêm các cạnh bằng hàm addEdge
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 3, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 4);

    // In ra danh sách kề
    printAdjList(adjList, n);

    return 0;
}
