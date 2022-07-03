 TreeNode<int> * build(vector<int> &nums, int s, int e){
        
            if(s > e) return NULL;
        
        int mid = s+ (e-s)/2;
        TreeNode<int> * root = new TreeNode<int>(nums[mid]);
        root->left = build(nums, s, mid-1);
        root->right = build(nums, mid+1, e);

        return root;
    }
    

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
     return build(arr, 0, n-1);
}