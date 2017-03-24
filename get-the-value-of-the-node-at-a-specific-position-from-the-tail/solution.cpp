int GetNode(Node *head, int positionFromTail)
{
    Node* tail = head;
    for(int i = 0; i < positionFromTail + 1; i++) {
        head = head->next;
    }
    while(head) {
        head = head->next;
        tail = tail->next;
    }
    return tail->data;
}
