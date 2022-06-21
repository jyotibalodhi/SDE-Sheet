/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<stack>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    
    vector<int> pre;
    vector<int> in;
    vector<int> pos;
    
    if(!root) return ans;
    
    stack<pair<BinaryTreeNode<int> *,int>> stk;
    
    stk.push({root,1});
    
    while(!stk.empty()){
        auto it = stk.top();
        stk.pop();
        
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            
            stk.push(it);
            if(it.first->left){
                stk.push({it.first->left, 1});
            }
        }
        
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            
            stk.push(it);
            
            if(it.first->right){
                stk.push({it.first->right, 1});
            }
        }
        
        else if(it.second == 3){
            pos.push_back(it.first->data);
        }
    }
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(pos);
    
    return ans;
}





