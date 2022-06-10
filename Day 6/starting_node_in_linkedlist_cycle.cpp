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
    Node* fast=head;
    Node* slow=head;
    Node* entry=head;
    
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        
        if(slow==fast)
        {
            while(entry!=slow)
            {
                entry=entry->next;
                slow=slow->next;
            }
            return entry;
        }
    }
    return NULL;
    
}