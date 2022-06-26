int getDiameter(TreeNode<int> * root, int &d){
    if(!root) return 0;
    
    int maxl = getDiameter(root->left,d);
    int maxr = getDiameter(root->right,d);
    
    d = max(d, maxl +maxr);
    
    return max(maxl,maxr) +1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter =0;
    
    getDiameter(root, diameter);
    return diameter;
}
