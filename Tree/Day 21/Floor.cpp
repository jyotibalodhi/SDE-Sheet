
int floorInBST(TreeNode<int> * root, int X)
{
    int ans;
    
    while(root){
        if(root->val > X){
            root = root->left;
        }
        else{
            ans = root->val;
            root = root->right;
        }
    }
    
    return ans;
}