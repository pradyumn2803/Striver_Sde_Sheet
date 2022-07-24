#include<queue>
void findMedian(int *arr, int n)
{
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int median;
    
    for(int i=0;i<n;i++)
    {
        if(max_heap.empty() || max_heap.top()>arr[i]) max_heap.push(arr[i]);
        else min_heap.push(arr[i]);
        
        if(max_heap.size()>1+min_heap.size())
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size()>1+max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
        if(max_heap.size()==min_heap.size()) median=(max_heap.top()+min_heap.top())/2;
        else if(max_heap.size()>min_heap.size()) median=max_heap.top();
        else median=min_heap.top();
        
        cout<<median<<" ";
    }
    cout<<"\n";
}