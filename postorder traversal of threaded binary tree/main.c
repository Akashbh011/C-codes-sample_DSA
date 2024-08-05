#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int lbit;
    int rbit;
    int flag;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->lbit = 0;
    node->rbit = 0;
    node->flag=0;
    return node;
}

void insert_node(struct Node** root_ptr, int data) {
    struct Node* node = create_node(data);
    struct Node* root = *root_ptr;
    if (root == NULL) {
        *root_ptr = node;
        return;
    }
    struct Node* curr = root;
    while (1) {
        if (data < curr->data) {
            if (curr->lbit == 0) {
                node->left = curr->left;
                node->right = curr;
                curr->left = node;
                curr->lbit = 1;
                break;
            }
            curr = curr->left;
        } else {
            if (curr->rbit == 0) {
                node->left = curr;
                node->right = curr->right;
                curr->right = node;
                curr->rbit = 1;
                break;
            }
            curr = curr->right;
        }
    }
}
void postorder( struct Node * root){
     root->flag=2;
     while(root!=NULL){

        if(root->left->flag!=1 && root->lbit!=0){

            root=root->left;
            root->flag=2;
        }
        else if(root->right->flag!=1 && root->rbit!=0){

            root=root->right;
            root->flag=3;

        }
        else{

            printf("%d ",root->data);
            if(root->flag ==2){

                root->flag=1;
                while(root->rbit!=0){
                    root=root->right;

                }
                root=root->right;
            }
            else{

                root->flag=1;
                while(root->lbit!=0){
                    root=root->left;
                }
                root=root->left;
            }

        }


     }


}



void inorder_traversal(struct Node* root) {
    struct Node* curr = root;
    while (curr->lbit == 1) {
        curr = curr->left;
    }
    while (curr != NULL) {
        printf("%d ", curr->data);
        if (curr->rbit == 1) {
            curr = curr->right;
            while (curr->lbit == 1) {
                curr = curr->left;
            }
        } else {
            curr = curr->right;
        }
    }
    printf("\n");
}

int main() {
    struct Node* root = create_node(30);
    insert_node(&root, 6);
    insert_node(&root, 3);
    insert_node(&root, 9);
    insert_node(&root, 1);
    insert_node(&root, 4);
    insert_node(&root, 7);
    insert_node(&root, 10);
    inorder_traversal(root);
    postorder(root);
    return 0;
}
