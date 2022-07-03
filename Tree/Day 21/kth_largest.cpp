  
    void solve(TreeNode<int>* root, int &k, int &ans){
        if(!root) return;
        
        // Reverse Inorder
       solve(root->right,k,ans);
       if(--k == 0){
           ans = root->data;
           return;
       }
       solve(root->left,k,ans);
       
       
    }

int KthLargestNumber(TreeNode<int>* root, int k) 
{
     
        int ans =-1;
         solve(root, k,ans);
         return ans;
}
