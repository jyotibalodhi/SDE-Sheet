int dfs(BinaryTreeNode<int> *root, bool &flag){
         if(!root) return 0;

        if(flag == false)  return 0;
        
        int maxl = dfs(root->left,flag);
        int maxr = dfs(root->right,flag);
        
        if(abs(maxl - maxr) >1) flag = false;
        return max(maxl,maxr) +1;
 }

bool isBalancedBT(BinaryTreeNode<int>* root) {
   bool flag= true;
        dfs(root,flag);

        return flag;
}