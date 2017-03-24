Node* InsertNth(Node *head, int data, int position)
{
    Node dummy;
    dummy.next = head;
    Node* ptr = &dummy;

    for(int i = 0; i < position; i++) {
        ptr = ptr->next;
    }
    Node* ins = new Node{data, ptr->next};
    ptr->next = ins;

    return dummy.next;
}
