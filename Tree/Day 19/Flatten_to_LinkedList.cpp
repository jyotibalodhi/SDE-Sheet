
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
     if(!root) return root;
        
        TreeNode<int> * curr = root;
        
        while(curr != NULL){
            if(curr->left){
                TreeNode<int>* node = curr->left;
                
                //Reaching the rightmost node of left child
                while(node->right)
                    node = node->right;
                
                node->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
                curr = curr->right;
        }
    
    return root;
}