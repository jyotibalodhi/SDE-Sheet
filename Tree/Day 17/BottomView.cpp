/*************************************************************
 
    Following is the Binary Tree node structure.

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

*************************************************************/

#include<queue>
#include<map>

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
 
    if (!root) return ans;
    
    queue<pair<BinaryTreeNode<int> *, int>> q;
    map<int, int> mp;
    
    q.push({root,0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        BinaryTreeNode<int> * node = it.first;
        int line = it.second;
        mp[line] = node->data;
        
        if(node->left) 
            q.push({node->left,line-1});
        
        if(node->right) 
            q.push({node->right,line+1});
    }
    
    for(auto i: mp){
        ans.push_back(i.second);
    }
    
    return ans;
    
}
