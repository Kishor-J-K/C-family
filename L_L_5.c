void revarse(struct Node *head)
{
    struct Node *prev, *temp, *next;
    temp = head;
    prev = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}