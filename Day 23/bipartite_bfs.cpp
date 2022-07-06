#include<queue>
bool bfs_bipartite(int node,vector<int> adj[],vector<int> &color)
{
    color[node]=0;
    queue<int> q;
    q.push(node);
    
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        
        for(auto it:adj[n])
        {
            if(color[it]==-1) 
            {
                color[it]=!color[n];
                q.push(it);
            }
            else if(color[it]==color[n]) return false;
        }
    }
    return true;
}

bool check_bipartite(vector<int> adj[],int n)
{
    vector<int> color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bfs_bipartite(i,adj,color)) return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size();
	vector<int> adj[n];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(edges[i][j]==1) 
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    if(check_bipartite(adj,n)) return true;
    return false;
    
}