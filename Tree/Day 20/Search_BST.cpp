BinaryTreeNode<int> * help(BinaryTreeNode<int> *root, int val){
    
    if(!root) return NULL;
    
    if(root->data == val) return root;
    
    return (root->data > val) ? help(root->left, val) : help(root->right, val);
}
bool searchInBST(BinaryTreeNode<int> *root, int val) {
   if(!root) return NULL;
        
    if(help(root, val) == NULL)
        return false;
    
    return true;
    
}