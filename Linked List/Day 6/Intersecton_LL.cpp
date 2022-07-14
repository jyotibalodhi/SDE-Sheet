#include <bits/stdc++.h> 


int findIntersection(Node *head1, Node *head2)
{
    Node * ha = head1;
    Node * hb = head2;
    int n = 0;
    
    while(ha != hb && n<=2){
        if(ha->next) ha= ha->next;
        else {
            ha = head2;
            n++;
        }
        
        if(hb->next) hb= hb->next;
        else{
            hb = head1;
            n++;
        }
    }
    
    if(n>2) return -1;
    return ha->data;
    
}