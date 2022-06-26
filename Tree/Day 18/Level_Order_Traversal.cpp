#include<queue>

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root)  return {};

        vector<int> ans;
                
        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                BinaryTreeNode<int> * node = q.front();
                q.pop();
                
                ans.push_back(node->val);

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return ans;
}