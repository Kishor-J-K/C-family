// Linked List: Delete a node at n'th position

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void print()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n)
{
    struct Node *temp;
    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp->next;
    }
    temp = temp2->next;
    temp2->next = temp->next;
    free(temp);
}

void Insert(int x, int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }

    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

int main()
{
    head = NULL;  // empty list
    Insert(2, 1); // List: 2
    Insert(3, 2); // List: 2 3
    Insert(4, 1); // List: 4 2 3
    Insert(5, 2); // List: 4 5 2 3
    print();
    Delete(2);
    print(); // list: 4 2 3
}
