void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &storedfs)
{
    storedfs.push_back(node);
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,storedfs);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> storedfs;
    vector<int> vis(V+1,0);
    vector<vector<int>> ans;
    
    vector<int> adj[V+1];
    
    for(int i=0;i<E;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=0;i<V;i++)
    {
        if(!vis[i]){
            dfs(i,vis,adj,storedfs);
            ans.push_back(storedfs);  
            storedfs.clear();
        }
    }
    
    return ans;
}