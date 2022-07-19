#include <bits/stdc++.h> 

Node *rotate(Node *head, int k) {
     
    if(!head || !head->next || k==0) return head;
    
    int n =0;  //length of list
    Node * fast= head;
    Node * slow= head;
    
    while(fast){
        n++;
        fast = fast->next;
    }
    
    if(k % n ==0) return head;
    k= k % n;
    
    int n1 =k;
    
    fast = head;
    while(n1--){
        fast = fast->next;
    }
    
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    
    return head;
    
    
}