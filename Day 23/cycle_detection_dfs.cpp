#include<queue>

bool check_cycle(int node,int par,vector<int> &vis,vector<int> adj[])
{
    vis[node]=1;
    
   for(auto it:adj[node])
   {
       if(!vis[it])
       {
           if(check_cycle(it,node,vis,adj)) return true;
       }
      else if(par!=it) return true;
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
            if(check_cycle(i,-1,vis,adj)) return "Yes";
        }
    }
    return "No";
}
