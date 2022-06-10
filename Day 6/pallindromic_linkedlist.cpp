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
LinkedListNode<int> *reverse_ll(LinkedListNode<int>* head)
{
    LinkedListNode<int> *newhead=NULL;
    
    while(head!=NULL)
    {
        LinkedListNode<int> *nex=head->next;
        head->next=newhead;
        newhead=head;
        head=nex;
    }
    return newhead;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL) return true;
    LinkedListNode<int> *s=head;
    LinkedListNode<int> *f=head;
    
    while(f->next && f->next->next)
    {
        s=s->next;
        f=f->next->next;
    }
    s->next=reverse_ll(s->next);
    s=s->next;
    f=head;
    while(s!=NULL)
    {
        if(s->data!=f->data) return false;
        s=s->next;
        f=f->next;
    }
    return true;
    
}