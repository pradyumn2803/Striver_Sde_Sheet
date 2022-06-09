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

Node *addTwoNumbers(Node *head1, Node *head2)
{
//     if(head1==NULL && head2==NULL) return head1;
    Node* dummy=new Node(0);
    Node* temp=dummy;
    int c=0;
    while(head1!=NULL || head2!=NULL || c!=0)
    {
        int sum=0;
        
        if(head1!=NULL)
        {
            sum+=head1->data;
            head1=head1->next;
        }
        
        if(head2!=NULL)
        {
            sum+=head2->data;
            head2=head2->next;
        }
        
        sum+=c;
        c=sum/10;
        Node* node= new Node(sum%10);
        temp->next=node;
        temp=node;
    }
    return dummy->next;
}