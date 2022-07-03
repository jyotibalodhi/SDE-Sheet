#include<queue>

void connectNodes(BinaryTreeNode< int > *root) {
    
    if(!root) return;
    
      queue<BinaryTreeNode< int > *> q;
      q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        
        for(int i=0;i<n;i++){
            BinaryTreeNode< int > * node = q.front();
            q.pop();
            
            if(i ==n-1)
                node->next = NULL;
            else
                node->next = q.front();
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}