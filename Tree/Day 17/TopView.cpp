#include<queue>
#include<map>

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    
    if(!root) return ans;
    
    queue<pair<TreeNode<int> *, int>> q;
    map<int,int> mp;
    
    q.push({root, 0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        TreeNode<int> * node = it.first;
        int line = it.second;
        
        if(mp.find(line)== mp.end())  // if not already present
            mp[line] = node->val;
        
        if(node->left)
            q.push({node->left,line-1});
        
        if(node->right)
            q.push({node->right,line+1});
    }
    
    
    for(auto i:mp){
        ans.push_back(i.second);
    }
    
    return ans;
}