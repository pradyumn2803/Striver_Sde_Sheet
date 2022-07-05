#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> toposort;
    vector<int> indegree(v+1,0);
    vector<int> adj[v+1];
    
    for(int i=0;i<e;i++) adj[edges[i][0]].push_back(edges[i][1]);
    
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i]) indegree[it]++;
    }
    
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    
    while(!q.empty())
    {
        int node=q.front();
        toposort.push_back(node);
        q.pop();
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return toposort;
}