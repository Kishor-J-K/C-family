// stack- Linked list implementation

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};

struct Node *top;

void push(int x)
{
    struct Node *temp = (struct Node *)malloc((sizeof(struct Node)));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void pop()
{
    struct Node *temp;
    if (top == NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
}

void print()
{
    if (top == NULL)
        return;
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    top = NULL;
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    pop();
    pop();
    pop();
    print();
}
