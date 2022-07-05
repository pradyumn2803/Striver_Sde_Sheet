#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> indegree(n+1,0);
    vector<int> adj[n+1];
    queue<int> q;
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    
    int cnt=0;
    while(!q.empty())
    {
        int node=q.front();
        cnt++;
        q.pop();
        
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    
    if(cnt==n) return false;
    return true;
}