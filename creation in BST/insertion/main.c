#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node{    ;
    int data;
    struct node * left ;
    struct node * right;

     };

struct node * createNode(int data){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;


};
void inorder(struct node* root){
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);

    }

}


void insert(struct node * root,int x){
    struct node *prev=NULL;
    while(root!=NULL){
            prev=root;
        if(x==root->data){
            printf("cannot insert --- ALREADY IN BST---\n");
            return;
        }

        else if(x<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
        }
        struct node * a =createNode(x);

        if(x<prev->data){
            prev->left=a;
        }
        else{
            prev->right=a;
        }

}
void mirror(struct node * root){
    struct node* temp;
    if(root!=NULL){
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }

}

int main()
{
 // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    /*struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;*/
    int A[]={4,6,76,56,3};
    int n=5;
    for(int i=0;i<n;i++){
        insert(p,A[i]);
    }

    //insert(p, 16);
    //printf("%d", p->right->right->data);
    inorder(p);
    printf("mirror--->");
    mirror(p);
    inorder(p);
    return 0;
}
