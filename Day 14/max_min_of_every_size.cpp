#include<stack>

vector<int> next_smaller(vector<int> &arr,int n)
{
    vector<int> next(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        
        if(st.empty()) next[i]=n;
        else next[i]=st.top();
        st.push(i);
    }
    return next;
}

vector<int> prev_smaller(vector<int> &arr,int n)
{
    vector<int> prev(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        
        if(st.empty()) prev[i]=-1;
        else prev[i]=st.top();
        st.push(i);
    }
    return prev;
}

vector<int> maxMinWindow(vector<int> arr, int n) {
    // Write your code here.
    vector<int> ans(n,-1e9);
    
    vector<int> ns=next_smaller(arr,n);
    vector<int> ps=prev_smaller(arr,n);
    
    for(int i=0;i<n;i++)
    {
        int l=ns[i]-ps[i]-1;
        
        ans[l-1]=max(ans[l-1],arr[i]);
    }
    
    for(int i=n-2;i>=0;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}