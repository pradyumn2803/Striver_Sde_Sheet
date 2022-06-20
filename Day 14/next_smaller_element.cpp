#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n,-1);
    stack<int> st;
    for(int i= n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]<=st.top())
        {
            st.pop();
        }
        
        if(!st.empty()) nse[i]=st.top();
        st.push(arr[i]);
    }
    return nse;
}