#include <stdio.h>
#include <stdlib.h>


//binary tree creation using the given array--

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insertNode(int arr[], struct Node* node, int i, int n) {
    if (i < n) {
        struct Node* temp = newNode(arr[i]);
        node = temp;
        node->left = insertNode(arr, node->left, 2*i+1, n);
        node->right = insertNode(arr, node->right, 2*i+2, n);
    }
    return node;
}

void printInorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = insertNode(arr, root, 0, n);
    printf("Inorder traversal of the constructed binary tree: \n");
    printInorder(root);

    return 0;
}
