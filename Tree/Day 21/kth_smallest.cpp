TreeNode<int>* solve(TreeNode<int>* root, int &k){
        
       if(root==NULL)
            return NULL;
    
    TreeNode<int> * left = solve(root->left,k);
        
    if(left!=NULL)
        return left;
    k--;
        
    if(k==0)
        return root;
    
    return solve(root->right,k);
        
    }

int kthSmallest(TreeNode<int> *root, int k)
{
	TreeNode<int> * node = solve(root, k);
        return node->data;
}