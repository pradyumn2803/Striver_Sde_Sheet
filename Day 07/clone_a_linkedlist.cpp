#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head==NULL) return head;
    LinkedListNode<int>* temp=head;
    
    while(temp!=NULL)
    {
        LinkedListNode<int>* node=new LinkedListNode<int>(temp->data);
        node->next=temp->next;
        temp->next=node;
        temp=temp->next->next;
    }
    
    temp=head;
    while(temp!=NULL)
    {
        if(temp->random!=NULL)
        {
            temp->next->random=temp->random->next;
        }
        else temp->next->random=NULL;

        temp=temp->next->next;
    }
    temp=head;
    LinkedListNode<int>* d=new LinkedListNode<int>(0);
    d->next=temp->next;
    LinkedListNode<int>* t=d;
    
    LinkedListNode<int>* iter=head;

    while(iter!=NULL)
    {
        LinkedListNode<int>* front=iter->next->next;
        t->next=iter->next;
        iter->next=front;
        t=t->next;
        iter=front;
    }
    
    return d->next;
}
