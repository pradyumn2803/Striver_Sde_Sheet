struct node
{
    int *arr;
    int top;
    int size;
};


// Stack class.
class Stack {
    node* st=new node();
public:
    
    Stack(int capacity) {
        // Write your code here.
        st->top=-1;
        st->size=capacity;
        st->arr=new int[capacity];
    }

    void push(int num) {
        // Write your code here.
        if(isFull()) return ;
        st->top+=1;
        st->arr[st->top]=num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty()) return -1;
        int ele=st->arr[st->top];
        st->top-=1;
        return ele;
    }
    
    int top() {
        // Write your code here.
        if(st->top==-1) return -1;
        return st->arr[st->top];
    }
    
    int isEmpty() {
        // Write your code here.
        return (st->top==-1);
    }
    
    int isFull() {
        // Write your code here.
        return (st->top == (st->size-1));
    }
    
};