#include<queue>
#include<algorithm>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> bfs;
    vector<int> vis(vertex+1,0);
//     sort(edges.begin(),edges.end());
    vector<int> adj[vertex+1];
    
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    for(int i=0;i<vertex;i++)
    {
        sort(adj[i].begin(),adj[i].end());
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;
            
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                
                for(auto it:adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return bfs;
}