#include <bits/stdc++.h> 


bool detectCycle(Node *head)
{
	Node * fast= head;
    Node * slow= head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow= slow->next;
        
        if(fast == slow) return true;
    }
    
    return false;

}