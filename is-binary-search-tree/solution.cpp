bool checkBSTStep(Node* node, int min, int max)
{
    if(nullptr == node) {
        return true;
    }
    if(node->data < min || node->data > max) {
        return false;
    }
    return checkBSTStep(node->left, min, node->data - 1) && checkBSTStep(node->right, node->data + 1, max);
}

bool checkBST(Node* root)
{
    const int min = -1000000;
    const int max = +1000000;
    return checkBSTStep(root, min, max);
}
