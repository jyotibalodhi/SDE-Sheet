#include<queue>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
   if(!root) return {};
        
        vector<int> ans;
        queue<BinaryTreeNode<int> *> q;
        
        q.push(root);
        bool leftToRight= true;
        
        while(!q.empty()){
            int size = q.size();
            int k = ans.size();
            ans.resize(k+ size);
           for (int i = 0; i < size; i++) {
              BinaryTreeNode<int> * node = q.front();
              q.pop();
               
              // find position to fill node's value
              int index = (leftToRight) ? i+k : (size - 1 -i +k);

              ans[index] = node -> data;
              if (node -> left) {
                q.push(node -> left);
              }
              if (node -> right) {
                q.push(node -> right);
              }
        }         
              leftToRight = !leftToRight;
        }
        return ans;
 }