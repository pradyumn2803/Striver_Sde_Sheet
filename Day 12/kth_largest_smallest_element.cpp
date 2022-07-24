#include<queue>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int,vector<int>,greater<int>> p;
    priority_queue<int> q;
    
    for(int i=0;i<n;i++)
    {
        p.push(arr[i]);
        q.push(arr[i]);
    }
    
    k-=1;
    while(k)
    {
        p.pop();
        q.pop();
        k--;
    }
    vector<int> ans(2,0);
    ans[0]=p.top();
    ans[1]=q.top();
    
    return ans;
}