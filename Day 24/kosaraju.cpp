#include<stack>
void topo_sort(int node,vector<int> &vis,vector<int> adj[],stack<int> &st)
{
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
            topo_sort(it,vis,adj,st);
    }
    st.push(node);
}

void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &ans,stack<int> &st)
{
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,ans,st);
        }
    }
    ans.push_back(node);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    
    vector<int> adj[n];
    
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            topo_sort(i,vis,adj,st);
    }
    
    vector<int> adj_tran[n];
    
//     for(int i=0;i<edges.size();i++)
//     {
//         adj_tran[edges[i][1]].push_back(edges[i][0]);
//     }
    
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            adj_tran[it].push_back(i);
        }
    }
    
    while(!st.empty())
    {
        int i=st.top();
        st.pop();
        if(!vis[i])
        {
            vector<int> v;
            dfs(i,vis,adj_tran,v,st);
            ans.push_back(v); 
        }         
    }
    
    return ans;
}