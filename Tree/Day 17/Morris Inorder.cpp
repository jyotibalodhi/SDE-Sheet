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
vector<int> getInOrderTraversal(TreeNode *root)
{
    
    //morris traversal solution
        vector<int> res;
        
        TreeNode * node = root;
    
    while(node){
        if(!node->left){
            res.push_back(node->data);
            node = node->right;
        }
        else{
            TreeNode * prev = node->left;
            while(prev->right && prev->right != node){
                prev= prev->right;
            }
            
            if(prev->right == NULL){  // no pre-existing thread
                // create a thread to node
                prev->right = node;
                node = node->left;
            }
            else{                       // prev->right == node
                prev->right = NULL;     // break the thread
                res.push_back(node->data);
                node = node->right;
            }
        }
    }
        
        return res;
}