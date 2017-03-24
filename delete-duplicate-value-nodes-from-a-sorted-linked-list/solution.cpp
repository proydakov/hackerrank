Node* RemoveDuplicates(Node *head)
{
    Node* root = head;
    while(head) {
        if(head->next && head->data == head->next->data) {
            head->next = head->next->next;
            continue;
        }
        head = head->next;
    }
    return root;
}
