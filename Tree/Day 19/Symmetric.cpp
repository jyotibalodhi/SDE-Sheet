 bool check(BinaryTreeNode<int>* p, BinaryTreeNode<int> *q){
        if(!p && !q)
            return true;
        
         if(!p || !q)
             return false;
        
        if(p->data != q->data) return false;
        
        return check(p->left,q->right) && check(p->right,q->left);
        
    }

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    
    return check(root->left, root->right);
}