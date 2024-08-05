#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct Node* constructHeap(int nodes[], int n, int index) {
    struct Node* node = NULL;
    if (index < n) {
        node = newNode(nodes[index]);
        node->left = constructHeap(nodes, n, 2*index + 1);
        node->right = constructHeap(nodes, n, 2*index + 2);
    }
    return node;
}

void heapTraversal(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;


    while (current != NULL || top != -1) {

        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }


        current = stack[top--];


        printf("%d ", current->data);


        current = current->right;
    }
}

int main() {
    int n, i;
    printf("Enter the number of nodes in the heap: ");
    scanf("%d", &n);
    int nodes[n];
    printf("Enter the values of the nodes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &nodes[i]);
    }

    struct Node* root = constructHeap(nodes, n, 0);


    printf("Heap traversal using stack: ");
    heapTraversal(root);

    return 0;
}
