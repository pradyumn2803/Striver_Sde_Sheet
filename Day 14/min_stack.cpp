// Implement class for minStack.
#include<limits.h>
class minStack
{
    // Write your code here.
    stack<long> st;
    long min;
    public:
        
        // Constructor
        minStack() 
        { 
            // Write your code here.
            min=INT_MAX;
        }
        
        // Function to add another element equal to num at the top of stack.
        void push(int num)
        {
            // Write your code here.
            long val=num;
            if(st.empty())
            {
                st.push(val);
                min=val;
            }
            else
            {
                if(val<min)
                {
                    st.push((2*val)-min);
                    min=val;
                }
                else
                {
                    st.push(val);
                }
            }
        }
        
        // Function to remove the top element of the stack.
        int pop()
        {
            // Write your code here.
            if(st.empty()) return -1;
            long res;
            long ele=st.top();
            st.pop();
            if(ele<min)
            {
                res=min;
                min=(2*min)-ele;
                return res;
            }
            res=ele;
            return res;
        }
        
        // Function to return the top element of stack if it is present. Otherwise return -1.
        int top()
        {
            // Write your code here.
            if(st.empty()) return -1;
            long ele=st.top();
            
            if(ele<min) return min;
            return ele;
        }
        
        // Function to return minimum element of stack if it is present. Otherwise return -1.
        int getMin()
        {
            // Write your code here.
            if(st.empty()) return -1;
            return min;
        }
};