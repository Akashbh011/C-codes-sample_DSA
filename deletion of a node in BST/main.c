#include <stdio.h>
#include <stdlib.h>


struct node {
 int data;
 struct node * left;
 struct node  * right;

};


struct node * inorderpre(struct node * root){
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
};

struct node * deleteinBST(struct node * root,int value){

    struct node * ipre;

    if(root==NULL){

        return NULL;
    }
    else if(root->right==NULL  &&  root->left==NULL){

        free(root);
        return NULL;
    }

   else if(value<root->data){

        root->left=deleteinBST(root->left,value);

    }
   else if(value>root->data){

        root->right=deleteinBST(root->right,value);

    }
    else{

        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=deleteinBST(root->left,ipre->data);
    }
    return root;


};
 struct node * createnode( int data){
  struct node *n =(struct node*)malloc(sizeof(struct node));
  n->data=data;
  n->right=NULL;
  n->left=NULL;

 };

 void inorder(struct node * root){
    if( root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    else{
        return NULL; }

 }


int main()
{
    struct node * p=createnode(5);

    struct node * p1=createnode(3);

    struct node * p2=createnode(6);
    struct node * p3=createnode(1);
    struct node * p4=createnode(4);

     p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    deleteinBST(p,3);
    printf("\n");
    inorder(p);





    return 0;
}
