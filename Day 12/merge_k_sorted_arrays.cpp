#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&a, int k)
{
    vector<int> ans;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<k;i++) pq.push({a[i][0],{i,0}});
    
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        
        int val=p.first;
        int row=p.second.first;
        int col=p.second.second;
        ans.push_back(val);
        
        if(col+1<a[row].size()) pq.push({a[row][col+1],{row,col+1}}); 
    }
    return ans;
}
