
#include<stack>

//function to check if a node is leaf node or not
bool isLeaf(TreeNode<int> * node){  
    if(!node->left && !node->right) return true;
    return false;
}

void addLeftNodes(TreeNode<int> * root, vector<int> &res){
    if(!root) return;
    
    TreeNode<int> * curr= root->left;
    while(curr){
        if(!isLeaf(curr))
            res.push_back(curr->data);
        
        if(curr->left) curr = curr->left;
        else
            curr = curr->right;
    }
}


void addLeaves(TreeNode<int> * root, vector<int> &res){
    if(isLeaf(root))
        res.push_back(root->data);
    
    if(root->left) 
        addLeaves(root->left,res);
    if(root->right) 
        addLeaves(root->right,res);
}

void addRightNodes(TreeNode<int> * root, vector<int> &res){
     if(!root) return;
    
    TreeNode<int> * curr= root->right;
    stack<int> stk;
    while(curr){
        if(!isLeaf(curr))
            stk.push(curr->data);
        
        if(curr->right) curr = curr->right;
        else
            curr = curr->left;
    }
    
    while(!stk.empty()){   // anticlockwise right tree
        res.push_back(stk.top());
        stk.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    
    if(!root)
        return {};
    
    vector<int> res;
    if(!isLeaf(root))  
        res.push_back(root->data); // now we won't add root again in left tree
    
    addLeftNodes(root,res);  // excluding leaf nodes
    addLeaves(root,res);
    addRightNodes(root,res); // excluding leaf nodes
    
    return res;
    
    
}