#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
    
    if(head==NULL || head->next==NULL || k==0) return head;
    
    int cnt=1;
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    
    temp->next=head;
    k=cnt-(k%cnt);
    
    while(k--)
    {
        temp=temp->next;
    }
    
    head=temp->next;
    temp->next=NULL;
    
    return head;
}