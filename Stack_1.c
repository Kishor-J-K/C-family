// Stack - Array based implementation.

#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("error: stack overflow\n");
        return;
    }
    A[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("error: No element to pop\n");
        return;
    }
    top--;
}

int Top()
{
    return A[top];
}

void print()
{
    int i;
    printf("stack: ");
    for (i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    push(2);
    print();
    push(3);
    print();
    push(4);
    print();
}