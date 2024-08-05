#include <stdio.h>
#define MAX 10

int main() {
    int stack[MAX];
    int top = -1;
    int n, i, a = 0, b = 1, c;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");

    // Push initial values onto the stack
    stack[++top] = a;
    stack[++top] = b;

    for(i = 2; i < n; i++) {
        // Pop the top two values from the stack
        b = stack[top--];
        a = stack[top--];

        // Calculate the next Fibonacci number
        c = a + b;

        // Push the result onto the stack
        stack[++top] = b;
        stack[++top] = c;

        // Print the result
        printf("%d ", c);
    }

    return 0;
}
