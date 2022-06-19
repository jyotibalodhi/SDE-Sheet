
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *newHead= NULL;
    LinkedListNode<int> *curr=head;

    while(head){
        curr= head->next;
        head->next = newHead;
        newHead = head;
        head= curr;
    }
    
    return newHead;
}