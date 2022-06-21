/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<queue>

int getMaxWidth(TreeNode<int> *root)
{
   if(!root) return 0;
    
    queue<TreeNode<int> *> q;
    q.push(root);
    
    int ans=0, len=0;
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0;i<size;i++){
            TreeNode<int> * node = q.front();
            q.pop();
            
            if(node->left) 
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
        }   
        len = q.size();
        ans = max(ans, len);
        len=0;
    }
    
    return max(ans,1);
}