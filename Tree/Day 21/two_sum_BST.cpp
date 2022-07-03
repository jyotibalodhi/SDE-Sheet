#include<stack>

class BSTIterator {
    stack<BinaryTreeNode<int> *> myStack;
    bool reverse = true; 
public:
    BSTIterator(BinaryTreeNode<int> *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

   
    bool hasNext() {
        return !myStack.empty();
    }

   
    int next() {
        BinaryTreeNode<int> *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }

private:
    void pushAll(BinaryTreeNode<int> *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
}