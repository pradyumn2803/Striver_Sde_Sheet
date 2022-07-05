#include<stack>

void dfs_topo(int node,vector<int> &vis,vector<int> adj[],stack<int> &st)
{
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs_topo(it,vis,adj,st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> toposort;
    vector<int> vis(v,0);
    vector<int> adj[v];
    stack<int> st;
    
    for(int i=0;i<e;i++) adj[edges[i][0]].push_back(edges[i][1]);
    
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs_topo(i,vis,adj,st);
        }
    }
    
    while(!st.empty())
    {
        toposort.push_back(st.top());
        st.pop();
    }
    
    return toposort;
}