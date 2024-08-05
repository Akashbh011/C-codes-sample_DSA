#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/')
        return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2;
    else
        return 0;
}

char* infixToPrefix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * prefix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i = strlen(infix) - 1; // Track infix traversal from right to left
    int j = 0; // Track prefix addition
    while (i >= 0)
    {
        if(!isOperator(infix[i])){
            prefix[j] = infix[i];
            j++;
            i--;
        }
        else{
            if(precedence(infix[i]) >= precedence(stackTop(sp))){
                push(sp, infix[i]);
                i--;
            }
            else{
                prefix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        prefix[j] = pop(sp);
        j++;
    }
    prefix[j] = '\0';
    // Reverse the prefix expression
    int k = 0;
    j--;
    while (k < j)
    {
        char temp = prefix[k];
        prefix[k] = prefix[j];
        prefix[j] = temp;
        k++;
        j--;
    }
    return prefix;
}

int main()
{
    char * infix = "x-y/z-k*d";
    printf("prefix is %s", infixToPrefix(infix));
    return 0;
}
