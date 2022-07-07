#include<queue>
#include<limits.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices];
    
    for(int i=0;i<edges;i++)
    {
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    
    vector<int> dist(vertices,INT_MAX);
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    pq.push({0,source});
    
    while(!pq.empty())
    {
        int cur_dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        for(auto it:adj[node])
        {
            int next_node=it.first;
            int next_dist=it.second;
            
            if(cur_dist+next_dist<dist[next_node])
            {
                dist[next_node]=cur_dist+next_dist;
                pq.push(make_pair(dist[next_node],next_node));
            }
        }
    }
    return dist;
}
