#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Cấu trúc nút trong danh sách kề
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

// Hàm thêm cạnh
void addEdge(Node* adjList[], int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

// Hàm đếm số đỉnh liền kề với k
int countAdjacent(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, v;

    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    // Kiểm tra ràng buộc
    if (n <= 0 || v <= 0 || n >= MAX_VERTICES || v >= MAX_VERTICES) {
        printf("So dinh va canh phai trong khoang 0 < n, v < 100.\n");
        return 1;
    }

    Node* adjList[MAX_VERTICES] = {NULL}; // Khởi tạo danh sách kề

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(adjList, u, w);
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Dinh k khong hop le!\n");
        return 1;
    }

    int result = countAdjacent(adjList[k]);
    printf("So dinh ke voi %d la: %d\n", k, result);

    return 0;
}
