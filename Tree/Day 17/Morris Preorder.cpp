/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // morris traversal solution
    
        vector<int> res;
        
        TreeNode *node = root;
        
    while(node){
        if(node->left == NULL){
            res.push_back(node->data);
            node = node->right;
        }
        else{
            TreeNode * prev = node->left;
            
            while(prev->right && prev->right != node){
                prev= prev->right;
            }
            
            if(prev->right == NULL){
                res.push_back(node->data);
                prev->right = node;
                node= node->left;
            }
            else{
                prev->right = NULL;
                node = node->right;
            }
        }
    }
        return res;
}