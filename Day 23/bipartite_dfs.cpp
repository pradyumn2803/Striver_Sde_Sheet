
bool dfs_bipartite(int node,vector<vector<int>> &edges,vector<int> &color)
{
    if(color[node]==-1) color[node]=0;

    for(int i=0;i<edges.size();i++)
    {
        if(edges[node][i]==1)
        {
            if(color[i]==-1) 
            {
                color[i]=!color[node];
                if(!dfs_bipartite(i,edges,color)) return false;
            }
            else if(color[i]==color[node]) return false;
        }
     }
    return true;
}

bool check_bipartite(vector<vector<int>> &edges,int n)
{
    vector<int> color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs_bipartite(i,edges,color)) return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size();
	vector<int> adj[n];
    
    if(check_bipartite(edges,n)) return true;
    return false;
    
}