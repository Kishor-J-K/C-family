// Double linked list Implementation

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head; // Global variable pointing to head node

struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    struct Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void print()
{
    struct Node *temp = head;
    printf("forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node *temp = head;
    if (temp == NULL)
        return;

    // Go to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL; // empty list
    InsertAtHead(2);
    print();
    ReversePrint();
    InsertAtHead(4);
    print();
    ReversePrint();
    InsertAtHead(6);
    print();
    ReversePrint();
}