#include <stdio.h>
#include <stdlib.h>
int a = 0;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
void Insert(int x, int n)
{
    if (n > a + 1)
    {
        printf("position %d doesnot exist\n", n);
        return;
    }
    a++;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        printf("Insertion successful\n");
        return;
    }
    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    printf("Insertion successful\n");
}

void print()
{
    if (head == NULL)
    {
        printf("the list is empty\n");
        return;
    }

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
    if (n == 1)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
        struct Node *temp2 = head;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp = temp2->next;
        temp2->next = temp->next;
        free(temp);
    }
}

void reverse()
{
    if (head == NULL)
    {
        printf("the list is empty");
        return;
    }

    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    head = NULL;
    int c, a, b;
    do
    {
        printf("***************************");
        printf("\n1.Insert\n2.Delete\n3.Print\n4.Reverse the list\n5.Exit\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("\nenter the number and position where to be inserted (a b): ");
            scanf("%d%d", &a, &b);
            Insert(a, b);
            break;

        case 2:
            printf("\nenter position of the number to be deleted: ");
            scanf("%d", &b);
            Delete(b);
            break;

        case 3:
            print();
            break;

        case 4:
            reverse();
            printf("\nlist after reversing: ");
            print();
        case 5:
            break;

        default:
            printf("\nplease enter a valid choice\n");
            break;
        }
    } while (c != 5);
}