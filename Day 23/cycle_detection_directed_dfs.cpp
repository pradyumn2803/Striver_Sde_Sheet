bool check_cycle(int node,vector<int> &vis, vector<int> &dfsvis, vector<int> adj[])
{
    vis[node]=1;
    dfsvis[node]=1;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(check_cycle(it,vis,dfsvis,adj)) return true;
        }
        else if(dfsvis[it]) return true;
    }
    dfsvis[node]=0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> vis(n+1,0),dfsvis(n+1,0);
    vector<int> adj[n+1];
    
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(check_cycle(i,vis,dfsvis,adj)) return true;
        }
    }
    return false;
}