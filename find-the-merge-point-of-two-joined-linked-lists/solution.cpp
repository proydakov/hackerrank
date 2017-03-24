
int Len(Node* node)
{
    int len = 0;
    while(node) {
        node = node->next;
        len++;
    }
    return len;
}

int FindMergeNode(Node* headA, Node* headB)
{
    int lenA = Len(headA);
    int lenB = Len(headB);

    while(lenA != lenB) {
        if(lenA > lenB) {
            lenA--;
            headA = headA->next;
        }
        else {
            lenB--;
            headB = headB->next;
        }
    }

    while(headA->data != headB->data) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA->data;
}
