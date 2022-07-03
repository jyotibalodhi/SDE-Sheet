#include<queue>
#include<sstream>
#include<string>

string serializeTree(TreeNode<int> *root)
{
 string s = "";
        
        if(!root){
            return s;
        }
        
        queue<TreeNode<int>*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode<int> * node = q.front();
            q.pop();
            
            if(node)
            {
               s.append(to_string(node->data) + ',');
            }
            else{
                s += "*,";   // if node alue is null
            }
            
           if(node){
               q.push(node->left);
               q.push(node->right);
           }
        }
        
        return s;

}

TreeNode<int>* deserializeTree(string &data)
{
  if(data.length()== 0) return NULL;
        
        stringstream s(data);     // to associate a string object with the string data
        string str;
        
        getline(s, str, ',');
        
        TreeNode<int>* root = new TreeNode<int>(stoi(str));
        
        queue<TreeNode<int>*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode<int>* node = q.front();
            q.pop();
            
            getline(s,str,',');
            
            if(str == "*"){
               node->left = NULL;
            }
            else{
                TreeNode<int> * leftNode = new TreeNode<int>(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s,str,',');
            
             if(str == "*"){
                node->right = NULL;
            }
            else{
                TreeNode<int> * rightNode = new TreeNode<int>(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }   
        }
        
        return root;

}



