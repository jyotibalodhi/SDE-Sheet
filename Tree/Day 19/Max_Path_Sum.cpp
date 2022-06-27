#define lli long long int

 lli path(TreeNode<int> * root, lli &maxi){
        if(!root) 
            return 0;
        
        lli leftSum = path(root->left,maxi);
        lli RightSum = path(root->right,maxi);

        maxi = max(maxi, leftSum +RightSum + root->val);
        
        return root->val + max(leftSum,RightSum);
        
 }

long long int findMaxSumPath(TreeNode<int> *root)
{
    
    if(!root) return -1;
    
    if(!root->left || !root->right) return -1;
        lli maxi = 0;
        
        path(root,maxi);
        return maxi;
}