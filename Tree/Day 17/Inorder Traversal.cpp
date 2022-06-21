class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // iterative solution
        
        stack<TreeNode *> stk;
        vector<int> res;
        
        TreeNode * node = root;
        
        while(1){
            if(node){
                stk.push(node);
                node = node->left;
            }
            else{
                if(stk.empty()) break;
                
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        
        return res;
    }
};