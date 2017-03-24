Node* MergeLists(Node* headA, Node* headB)
{
    Node dummy;
    dummy.next = nullptr;
    Node* current = &dummy;
    while(headA != nullptr && headB != nullptr) {
        if(headA->data < headB->data) {
            current->next = headA;
            headA = headA->next;
        }
        else {
            current->next = headB;
            headB = headB->next;
        }
        current = current->next;
    }
    if(headA != nullptr) {
        current->next = headA;
    }
    if(headB != nullptr) {
        current->next = headB;
    }
    return dummy.next;;
}
