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

Node *findMiddle(Node *head) {
    Node* s=head;
    Node* f=head;
    while(f!=NULL && f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;      
    }
    return s;
}