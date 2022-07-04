#include<queue>
int kthLargest(vector<int>& arr, int n, int k)
{
	priority_queue<int> p;
    
    for(int i=0;i<n;i++) p.push(arr[i]);
    
    for(int i=1;i<k;i++) p.pop();
    
    return p.top();
}