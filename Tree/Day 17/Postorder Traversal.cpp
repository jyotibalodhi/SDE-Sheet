class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //iterative solution
        
        stack<TreeNode *> stk;
        vector<int> res;
        
        TreeNode* node =root;
        
        while(node || !stk.empty()){
            if(node){
                stk.push(node);
                node= node->left;
            }
            else{
                TreeNode * temp= stk.top()->right;
                
                if(!temp){
                    temp = stk.top();
                    stk.pop();
                    
                    res.push_back(temp->val);
                    
                    while(!stk.empty() && temp == stk.top()->right){
                        temp = stk.top();
                        stk.pop();
                        res.push_back(temp->val);
                    }
                }
                else{
                    node= temp;
                }
            }
        }
        
        return res;
    }
};