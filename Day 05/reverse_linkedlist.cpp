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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *new_head=NULL;
    while(head!=NULL)
    {
        LinkedListNode<int> *next=head->next;
        head->next=new_head;
        new_head=head;
        head=next;
    }
    return new_head;
}