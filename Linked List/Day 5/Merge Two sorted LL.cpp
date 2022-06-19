#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    if(!l1) return l2;
    if(!l2) return l1;
    
    if(l1->data > l2->data) swap(l1,l2);
    
    Node<int> * newHead = new Node<int> (1);
    newHead->next = l1;
    Node<int> * temp = newHead;
    
    while(l1 && l2){
        
        if(l1->data < l2->data){
            temp->next= l1;
            temp= l1;
            l1= l1->next;
        }
        else{
            temp->next= l2;
            temp= l2;
            l2= l2->next; 
        }
    }
    
    if(l1) temp->next = l1;
    if(l2) temp->next = l2;
    
    return newHead->next;
}
