
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	  while(root){
            if(root->data == p->data || root->data == q->data){
                break;
            }
            
            if(root->data < p->data && root->data < q->data)  // Both on right
                root= root->right;
            
            else if(root->data > p->data && root->data > q->data)// Both on left
                root = root->left;
            else                   //one on left other on right, so root becomes the lca
                break;
        }
        return root;
}