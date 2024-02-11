// Queue- Linked list implementation

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enque(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
void Deque()
{
    if (front == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    else if (front == rear)
    {
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("the list is empty\n");
        return;
    }

    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Enque(1);
    display();
    Enque(2);
    display();
    Enque(3);
    display();
    Enque(4);
    display();
    Enque(5);
    display();
    Deque();
    display();
    Deque();
    display();
    Deque();
    display();
}