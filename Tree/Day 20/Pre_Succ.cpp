

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
   
BinaryTreeNode<int> * temp = root;

int suc = -1;

//finding successor
while(temp){
    if(key >= temp->data){
        temp = temp->right;
    }
    else{
        suc = temp->data;
        temp = temp->left;
    }
}

temp = root;


//finding predecessor

int pre = -1;

while(temp){
    if(key <= temp->data){
        temp = temp->left;
    }
    else{
        pre = temp->data;
        temp = temp->right;
    }
}

    return {pre,suc};
}
