#include<limits.h>

 TreeNode<int>* ConBST(vector<int>& pre, int &i, int bound){
        
        if(i >=  pre.size() || pre[i] >bound) return nullptr;
        
        TreeNode<int> * root = new TreeNode<int>(pre[i]);
        i++;
        
        root->left = ConBST(pre, i, root->data);
        root->right = ConBST(pre, i, bound);
        
        return root;
    }

TreeNode<int>* preOrderTree(vector<int> &pre){
        int ind=0;
        return ConBST(pre, ind, INT_MAX); // preorder, starting index, upper bound for root
}