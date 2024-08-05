#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node * left;
    struct node  * right;

};

struct StackNode {
    struct node *node;
    struct StackNode *next;
};


struct Stack {
    struct StackNode *top;
};

struct StackNode* createStackNode(struct node *node) {
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

int isStackEmpty(struct Stack *stack) {
    return stack->top == NULL;
}


void push(struct Stack *stack, struct node *node) {
    struct StackNode* stackNode = createStackNode(node);
    stackNode->next = stack->top;
    stack->top = stackNode;
}



struct node* pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        return NULL;
    }
    struct node* node = stack->top->node;
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return node;
}


void inorderTraversal(struct node* root) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = NULL;
    struct node* current = root;
    while (current != NULL || !isStackEmpty(stack)) {
        if (current != NULL) {
            push(stack, current);
            current = current->left;
        } else {
            current = pop(stack);
            printf("%d ", current->data);
            current = current->right;
        }
    }
}

struct node * inorderpre(struct node * root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
};

struct node * deleteinBST(struct node * root,int value)
{

    struct node * ipre;

    if(root==NULL)
    {

        return NULL;
    }
    else if(root->right==NULL  &&  root->left==NULL)
    {

        free(root);
        return NULL;
    }

    else if(value<root->data)
    {

        root->left=deleteinBST(root->left,value);

    }
    else if(value>root->data)
    {

        root->right=deleteinBST(root->right,value);

    }
    else
    {

        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=deleteinBST(root->left,ipre->data);
    }
    return root;


};
struct node * createnode( int data)
{
    struct node *n =(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;

};
/*
void inorder(struct node * root)
{
    if( root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    else
    {
        return NULL;
    }

}

void inorder1(struct node * root){
    while(1){

        while(root!=NULL){

            if(root->right!=NULL){
                push(root->right,root->right->data);
            }
            root=root->left;
            printf("%d ",root->data);
        }
        if(!isEmpty(root)){

            root=pop(root);
        }
        else{
            break;
        }


    }

}
*/

void insert(struct node * root,int x)
{
    struct node *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(x==root->data)
        {
            printf("cannot insert --- ALREADY IN BST---\n");
            return;
        }

        else if(x<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    struct node * a =createnode(x);

    if(x<prev->data)
    {
        prev->left=a;
    }
    else
    {
        prev->right=a;
    }

}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printf("\n");
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
        printf("\n");
    }
}


int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


int main()
{
    int n;

    printf("enter the total number of elements you want to insert :");
    scanf("%d",&n);
    int A[n];
    printf("enter the elements one by one :");

    // struct node * p=createnode(5);

    for( int i=0; i<n; i++)
    {


        scanf("%d",&A[i]);

        //insert(p,A[i]);

    }
    struct node * p=createnode(A[0]);
    for (int i=1; i<n; i++)
    {
        insert(p,A[i]);

    }

    inorderTraversal(p);
    int a;
    printf("\n");
    printf("enter the data which you want to delete :");
    scanf("%d",&a);
    deleteinBST(p,a);
    printf("\n");
    inorderTraversal(p);
    printf("\n");
    printf("\nlevel wise traversal is:\n");
    printLevelOrder(p);




    return 0;
}
