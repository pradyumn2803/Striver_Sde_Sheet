#include<queue>
bool bfs_bipartite(int node,vector<vector<int>> &edges,vector<int> &color)
{
    color[node]=0;
    queue<int> q;
    q.push(node);
    
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        
        for(int i=0;i<edges.size();i++)
        {
            if(edges[n][i]==1)
            {
                if(color[i]==-1) 
                {
                    color[i]=!color[n];
                    q.push(i);
                }
                else if(color[i]==color[n]) return false;
            }
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
            if(!bfs_bipartite(i,edges,color)) return false;
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