#include<map>

TreeNode<int>* BT(vector<int>& pre, int preStr, int preEnd, vector<int>& in, int inStr, int inEnd, map<int,int> &mp){
        
        if(preStr > preEnd || inStr >inEnd) return NULL;
        
        TreeNode<int> * root = new TreeNode<int>(pre[preStr]);
        
        int ind = mp[root->data];
        int leftNum = ind - inStr;
        
        root -> left = BT( pre , preStr +1 , preStr + leftNum , in , inStr , ind-1, mp);
        root -> right = BT( pre , preStr + leftNum +1 , preEnd , in , ind+1 , inEnd , mp);
        
        return root;

}

TreeNode<int> *buildBinaryTree(vector<int> &in, vector<int> &pre)
{
	 map<int,int> mp;
        
        for(int i=0 ; i<in.size() ; i++){
            mp[in[i]] =i;
        }
        
        TreeNode<int> * root = BT(pre,0,pre.size()-1,in,0, in.size()-1,mp);
        
        return root;
}