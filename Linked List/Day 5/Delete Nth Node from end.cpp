#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    
    if(!head || k==0) return head;
    LinkedListNode<int> * dummy= new LinkedListNode<int>(1);
    dummy->next= head;
    
    LinkedListNode<int> * fast= dummy;
    LinkedListNode<int> * slow = dummy;

    while(k--){
        fast = fast->next;
    }
    
    while(fast->next){
        fast= fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    return dummy->next;
    
    
}