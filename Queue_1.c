// arrey implementation of circular queues

#include <stdio.h>
#define MAX_SIZE 5
int A[MAX_SIZE];
int front = -1, rear = -1;

void enque(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        A[rear] = x;
    }
    else if (front == 0 && rear == MAX_SIZE - 1 || front == rear + 1)
    {
        printf("\nthe queue is full\n");
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
        A[rear] = x;
    }
}

void deque()
{
    if (front == -1 && rear == -1)
    {
        printf("\nthe queue is already empty\n");
    }
    else if (front == rear)
    {
        printf("\ndeleted no is %d\n", A[front]);
        A[front] = 0;
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\ndeleted no is %d\n", A[front]);
        A[front] = 0;
        front = (front + 1) % MAX_SIZE;
    }
}

void display()
{
    int i;

    for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[i]);
}

int main()
{
    enque(1);
    display();
    enque(2);
    display();
    enque(3);
    display();
    enque(4);
    display();
    deque();
    display();
}