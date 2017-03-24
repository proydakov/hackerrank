Node* Reverse(Node *head)
{
    Node* next = nullptr;
    while(head) {
        Node* temp = head->next;
        head->next = next;
        next = head;
        head = temp;
    }
    return next;
}
