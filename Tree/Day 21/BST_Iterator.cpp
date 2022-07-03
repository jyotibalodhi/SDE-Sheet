#include<stack>

class BSTiterator
{
    public:
    
    stack<TreeNode<int> *> stk;
    
    void pushLeft(TreeNode<int>* node){
        while(node){
            stk.push(node);
            node = node->left;
        }
    }
    
    BSTiterator(TreeNode<int> *root)
    {
      pushLeft(root);
    }

    int next()
    {
       TreeNode<int> * node = stk.top();
        stk.pop();
        
        if(node->right)
            pushLeft(node->right);
        return node->data;
    }

    bool hasNext()
    {
       return !stk.empty();
    }
};

