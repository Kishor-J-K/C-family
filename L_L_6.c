
// consider the list to be: head -- [2] -- [6] -- [5] -- [4] -- NULL

// function to print list in reverse order using recursion
void reverseprint(struct Node *p)
{
    if (p == NULL)
    {
        return;
    }
    reverseprint(p->next);
    printf("%d\n", p->data);
}

// function to print in straight order using recursion
void print(struct Node *p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d\n", p->data);
    print(p->next);
}
