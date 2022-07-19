#include <bits/stdc++.h> 


LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    
    if(!head) return head;
    
    LinkedListNode<int> * curr = head;
    LinkedListNode<int> * front = head;
    
    
    //creating nodes of new linked list
    while(curr){
        front = curr->next;
        LinkedListNode<int> * node = new  LinkedListNode<int>(curr->data);
        curr->next = node;
        node->next = front;
        curr = front;     
    }
    
    curr = head;
    front = head;
    
    
    //populating random nodes of new linked list
    while(curr){
        front = curr->next->next;
        if(curr->random){
            curr->next->random = curr->random->next;
        }
        else{
            curr->next->random = NULL;
        }
        curr = front;
    }
      
    
    //Seperating the newly made linked list
     LinkedListNode<int> *newHead = new LinkedListNode<int>(0);
     LinkedListNode<int>* node = newHead;
    
    curr = head;
    front = curr;
    
    while(curr){
        front = curr->next->next;
        node->next = curr->next;
        curr->next = front;
        node = node->next;
        curr= front;
    }
    
    return newHead->next;
    
}
