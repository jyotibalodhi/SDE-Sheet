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

Node *findMiddle(Node *head) {
    
    if(!head || !head->next)  return head;
    
    Node * fast = head;
    Node * slow = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow= slow->next;
    }
    
    return slow;
}