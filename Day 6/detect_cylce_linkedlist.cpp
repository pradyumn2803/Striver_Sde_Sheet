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

bool detectCycle(Node *head)
{
	if(head==NULL || head->next==NULL) return NULL;
    
    Node* f=head;
    Node* s=head;
    
    while(f->next && f->next->next)
    {
        s=s->next;
        f=f->next->next;
        
        if(s==f) return true;
    }
    return false;
}