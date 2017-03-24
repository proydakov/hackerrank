Node* Delete(Node* head, int position)
{
    Node dummy;
    dummy.next = head;

    Node* ptr = &dummy;
    for(int i = 0; i < position; i++) {
        ptr = ptr->next;
    }

    ptr->next = ptr->next->next;
    return dummy.next;
}
