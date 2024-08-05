//vvvviiiimmmmmppppppp

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;

};



struct stack{
    int size ;
    int top;
    int * arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

struct node * createnode(int data)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;

};

struct node* inorderpre( struct node * root){
    root=root->left;
    while(root!=NULL){
        root=root->right;
    }
    return root;

};

struct node* deletenode(struct node * root,int data){

    struct node *ipre=NULL;
    if(root==NULL){

        return NULL;
    }

    if(root->right==NULL && root->left==NULL)
    {
        free(root);
        return NULL;
    }
    else if(data<root->data)
    {
        root->left=deletenode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=deletenode(root->right,data);
    }
    else{
        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=deletenode(root->left,ipre->data);
    }
    return root;




}

void inorder(struct node* root)
{

    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void insert(struct node* root,int data)
{
    struct node* prev=NULL;

    while(root!=NULL)
    {
        if(data<root->data)
        {
            prev=root;
            root=root->left;
        }
        else
        {
            prev=root;
            root=root->right;
        }

    }
    struct node* n=createnode(data);
    if(n->data<prev->data)
    {
        prev->left=n;
    }
    else
    {
        prev->right=n;
    }


}

void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->size = 100;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));

    push(stack, root);

    while (!isEmpty(stack)) {
        struct node *node = pop(stack);
        printf("%d ", node->data);

        if (node->right != NULL) {
            push(stack, node->right);
        }

        if (node->left != NULL) {
            push(stack, node->left);
        }
    }
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    struct stack *stack1 = (struct stack *)malloc(sizeof(struct stack));
    struct stack *stack2 = (struct stack *)malloc(sizeof(struct stack));
    stack1->size = 100;
    stack1->top = -1;
    stack1->arr = (int *)malloc(stack1->size * sizeof(int));
    stack2->size = 100;
    stack2->top = -1;
    stack2->arr = (int *)malloc(stack2->size * sizeof(int));

    push(stack1, root);

    while (!isEmpty(stack1)) {
        struct node *node = pop(stack1);
        push(stack2, node);

        if (node->left != NULL) {
            push(stack1, node->left);
        }

        if (node->right != NULL) {
            push(stack1, node->right);
        }
    }

    while (!isEmpty(stack2)) {
        struct node *node = pop(stack2);
        printf("%d ", node->data);
    }
}

void inorder1(struct node *root) {
    struct stack *stack = NULL;
    struct node *current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
}
void inorder2(struct node *root)
{   struct stack *stack1 = (struct stack *)malloc(sizeof(struct stack));
    struct stack *stack2 = (struct stack *)malloc(sizeof(struct stack));
    stack1->size = 100;
    stack1->top = -1;
    stack1->arr = (int *)malloc(stack1->size * sizeof(int));
    struct node *temp=root;
    while(temp!=NULL)
    {
        push(stack1,temp);
        temp=temp->left;
    }
    while(!isEmpty(stack1))
    {
        temp=pop(stack1);
        printf("%d ",temp->data);
        temp=temp->right;
        while(temp!=NULL)
        {
            push(stack1,temp);
            temp=temp->left;
        }
    }
}
/*
void preorder(struct node * root){
    if (root == NULL) {
        return;
    }
    struct node *n=NULL;
struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->size = 100;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));

    push(stack, root);
        while(1){
        while(root!=NULL){
                struct node *n=pop(stack);
            printf("%d ",n->data);
            if(n->right!=NULL){
                push(stack,n->right);
            }
            n=n->left;
        }
        if(!isEmpty(stack)){

            n=pop(stack);
        }else{
            break;
        }
    }
}
*/

int main()
{
    struct node* p=createnode(5);
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    insert(p,6);
    insert(p,8);
    inorder(p);
    deletenode(p,8);
    inorder(p);
    insert(p,7);
    insert(p,9);
    insert(p,44);
    inorder(p);
    printf(" \n");

    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n------");
    inorder1(p);

    return 0;
}
