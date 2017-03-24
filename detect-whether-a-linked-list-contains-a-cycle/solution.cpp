bool has_cycle(Node* head) {
    Node* h1 = head;
    Node* h2 = head;
    while(h1) {
        h1 = h1->next;
        if(h1 == nullptr) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
        if(h1 == h2) {
            return true;
        }
    }
    return false;
}
