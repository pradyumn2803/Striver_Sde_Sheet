#include<queue>
#include<algorithm>
class Stack {
	// Define the data members
    queue<int> q1;
   public:
    Stack() {
        // Implement the Constructor.  
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
        for(int i=0;i<q1.size()-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty()) return -1;
        int ele=q1.front();
        q1.pop();
        return ele;
    }

    int top() {
        if(q1.empty()) return -1;
        return q1.front();
        // Implement the top() function.
    }
};