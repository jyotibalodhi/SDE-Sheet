TreeNode<int>* dfs(TreeNode<int> * root,int x, int y){
        
        if(!root || root->data == x || root->data == y) return root;
        
        TreeNode<int>* left = dfs(root->left,x,y);
        TreeNode<int>* right = dfs(root->right,x,y);
        
        if(!left)  // LCA found in right
            return right;
        
        if(!right) // LCA found in left
            return left;
        
            return root;
 }

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
  TreeNode<int> *node = dfs(root,x,y);
    return node->data;
}