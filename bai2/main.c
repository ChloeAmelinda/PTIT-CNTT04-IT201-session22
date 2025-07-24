#include <stdio.h>
#include <stdlib.h>

// Cấu trúc danh sách kề
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo nút mới
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Thêm cạnh giữa hai đỉnh
void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// In danh sách kề
void printAdjList(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    Node* adjList[n];

    // Khởi tạo danh sách kề
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    // Thêm các cạnh bằng addEdge thay vì dùng mảng
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 3, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 4);

    // In danh sách kề
    printAdjList(adjList, n);

    return 0;
}
