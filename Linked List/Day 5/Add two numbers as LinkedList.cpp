#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
	        Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
      if(!l1) return l2;
         
        if(!l2) return l1;
        
        Node* l3 = new Node(-1);
        Node* curr= l3;
        
        int c=0,sum=0;
        
        while(l1 || l2){
            
           int val1 = l1 ? l1->data :0;
            int val2 = l2 ? l2->data :0;
            

            sum = val1 + val2 +c;
            
            c =sum/10;
            sum =sum %10;
            
            if(l3->data== -1) // empty list
            {
                l3->data = sum;
            }
            else{
                Node* temp =new Node(sum);
                curr->next = temp;
                curr =curr->next;
            }
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        
        if(c) {
             Node* temp =new Node(c);
                curr->next = temp;
        }
        
        return l3;
}