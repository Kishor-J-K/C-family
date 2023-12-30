
// Reversing linked list using function recursion

void Reverse(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }

    Reverse(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}
