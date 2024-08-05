#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{
    int size;
    int top;
    char **arr;
};

char* stackTop(struct stack* sp){
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

void push(struct stack* ptr, char* val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %s to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char* pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return NULL;
    }
    else{
        char* val = ptr->arr[ptr->top];
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

char* postfixToInfix(char* postfix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char **) malloc(sp->size * sizeof(char *));
    char * operand1, * operand2, * infixExp;
    int i = 0;
    while (postfix[i]!='\0')
    {
        if(isalpha(postfix[i])){
            infixExp = (char *) malloc(2 * sizeof(char));
            infixExp[0] = postfix[i];
            infixExp[1] = '\0';
            push(sp, infixExp);
        }
        else if(isOperator(postfix[i])){
            operand1 = pop(sp);
            operand2 = pop(sp);
            infixExp = (char *) malloc((strlen(operand2) + strlen(operand1) + 4) * sizeof(char));
            sprintf(infixExp, "(%s%c%s)", operand2, postfix[i], operand1);
            push(sp, infixExp);
        }
        i++;
    }
    return pop(sp);
}

int main()
{
    char * postfix = "xyz/-kd*-*";
    printf("infix is %s", postfixToInfix(postfix));
    return 0;
}
