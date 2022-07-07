#include<limits.h>
#include<queue>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<pair<int, int>, int>> ans;
    
    vector<pair<int,int>> adj[n+1];
    
    for(int i=0;i<m;i++)
    {
        adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    
    vector<int> key(n+1,INT_MAX),parent(n+1,-1);
    vector<bool> mst(n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    key[1]=0;
    
    pq.push({0,1});
    while(!pq.empty())
    {
        int ind=pq.top().second;
        pq.pop();
        mst[ind]=true;
        
        for(auto it:adj[ind])
        {
            int node=it.first;
            int weight=it.second;
            
            if(!mst[node] && key[node]>weight)
            {
                key[node]=weight;
                parent[node]=ind;
                pq.push({key[node],node});
            }
        }
    }
    
    for(int i=2;i<=n;i++)
    {
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
