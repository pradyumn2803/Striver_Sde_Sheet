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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head ==  NULL  || K==0) return head;
    LinkedListNode<int> *start=new LinkedListNode<int>(0);
    start->next = head;
    LinkedListNode<int> *f=start;
    LinkedListNode<int> *s=start;

    
    for(int i=1;i<=K;i++)
    {
        f=f->next;
    }
    
    while(f->next!=NULL)
    {
        f=f->next;
        s=s->next;
    }
    
    s->next=s->next->next;
    return start->next;
}