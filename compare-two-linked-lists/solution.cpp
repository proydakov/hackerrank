int CompareLists(Node* headA, Node* headB)
{
    while(headA != nullptr && headB != nullptr) {
        if(headA->data != headB->data) {
            return false;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return headA == headB;
}
