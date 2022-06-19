struct node
{
    int *arr;
    int rear,front;
    int size;
};

class Queue {
    int cnt;
    node* q=new node();
public:
    Queue() {
        // Implement the Constructor
        q->arr=new int[5001];
        q->rear=q->front=0;
        cnt=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (cnt==0);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q->arr[q->rear]=data;
        q->rear=q->rear+1;
        cnt++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        int ele=q->arr[q->front];
        q->front=q->front+1;
        cnt--;
        return ele;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return q->arr[q->front];
    }
};