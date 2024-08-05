#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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

char stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int palindromeCheck(char * exp){
    int count=0;
    char c;
    int len = strlen(exp);
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    struct stack* sp1 = (struct stack*)malloc(sizeof(struct stack));
    sp->size = len;
    sp1->size = len;
    sp->top = -1;
    sp1->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    sp1->arr = (char *)malloc(sp1->size * sizeof(char));

    for (int i = 0; i<len; i++)
    {
        push(sp, exp[i]);
        //printf(" %c ",exp[i]);


    }

    for (int i = 0; i<len; i++)
    {
        if(pop(sp)==exp[i]){
            count++;
        }
        else{
            count=0;
        }

    }
    if(count==len){
        return 1;
    }else{
    return 0;}



}
int main()
{
    char exp[100];
    printf("Enter a string: ");
    fgets(exp,100,stdin);

    if(palindromeCheck(exp)){
        printf("yes its a palindrome");
    }
    else{
        printf("its not a palindrome");
    }
    return 0;
}
