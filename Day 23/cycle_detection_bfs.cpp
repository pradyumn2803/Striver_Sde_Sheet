#include<queue>

bool check_cycle(int node,vector<int> &vis,vector<int> adj[])
{
    queue<pair<int,int>> q;
    q.push({node,-1});
    vis[node]=1;
    
    while(!q.empty())
    {
        int n=q.front().first;
        int par=q.front().second;
        q.pop();
        
        for(auto it:adj[n])
        {
            if(!vis[it])
            {
                q.push({it,n});
                vis[it]=1;
            }
            else if(par!=it) return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> vis(n+1,0);
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(check_cycle(i,vis,adj)) return "Yes";
        }
    }
    return "No";
}
