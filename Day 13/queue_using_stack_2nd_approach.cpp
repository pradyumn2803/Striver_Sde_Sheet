#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> input,output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(input.empty() && output.empty()) return -1;
        
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int ele=output.top();
        output.pop();
        return ele;
    }

    int peek() {
        // Implement the peek() function here.
        if(input.empty() && output.empty()) return -1;
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (input.empty() && output.empty());
    }
};