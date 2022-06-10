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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(head==NULL || head->next==NULL) return head;
    
    Node* dummy=new Node(0);
    dummy->next=head;
    
    Node* pre=dummy,*cur =dummy,*nex=dummy;
    int cnt=0;
    while(cur->next!=NULL)
    {
        cur=cur->next;
        cnt++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(b[i]==0) continue;
        int x;
        cur=pre->next;
        nex=cur->next;
        
        x=(cnt>=b[i])?b[i]:cnt;
        
        for(int j=1;j<x;j++)
        {
            cur->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=cur->next;
        }
        pre=cur;
        cnt-=x;
        if(cnt==0) break;
    }
    return dummy->next;
}