/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>* node, int level, vector<int> &ds){
    if(node== NULL) return;
    
    if(level == ds.size()) // making sure it's the first time coming to that level
    {
        ds.push_back(node->data);
    }
    
    solve(node->left,level+1,ds);
    solve(node->right,level+1,ds);
    
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> res;
    
    solve(root, 0, res);
    return res;
}