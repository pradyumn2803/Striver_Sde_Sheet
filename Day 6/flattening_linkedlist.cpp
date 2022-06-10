#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* merge(Node* a,Node* b)
{
    Node* temp=new Node(0);
    Node* d=temp;
    
    while(a && b)
    {
        if(a->data<b->data)
        {
            d->child=a;
            d=d->child;
            a=a->child;
        }
        
        else
        {
            d->child=b;
            d=d->child;
            b=b->child;
        }
        
    }
    
    if(a) d->child=a;
    else d->child=b;
    temp->child->next=NULL;
    return temp->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL) return head;
    
    head->next=flattenLinkedList(head->next);
    
    head=merge(head,head->next);
    
    return head;
}
