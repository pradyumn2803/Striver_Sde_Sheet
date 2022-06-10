#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node* f=head;
    Node* s=head;
    
    do
    {
        f=f->next->next;
        s=s->next;
    }while(f!=s && f && s && f->next);

    f=head;
    while(f!=s && f && s)
    {
        f=f->next;
        s=s->next;
    }
    
    return s;
}