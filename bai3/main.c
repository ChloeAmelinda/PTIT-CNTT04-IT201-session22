#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc node trong danh sách kề
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Mảng danh sách kề
Node* adjacencyList[MAX];

// Thêm node mới vào danh sách kề
void addToList(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;

    if (adjacencyList[src] == NULL) {
        adjacencyList[src] = newNode;
    } else {
        Node* temp = adjacencyList[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hiển thị danh sách kề
void printAdjacencyList(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = adjacencyList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    printf("enter n (0 < n < 100): ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX) {
        printf("invalible!\n");
        return 1;
    }

    int matrix[n][n];

    // Khởi tạo danh sách kề rỗng
    for (int i = 0; i < n; i++) {
        adjacencyList[i] = NULL;
    }

    printf("enter maxtrix(%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Chuyển từ ma trận sang danh sách
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                addToList(i, j);
            }
        }
    }

    printf("\n matrix:\n");
    printAdjacencyList(n);

    return 0;
}
