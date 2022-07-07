
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[edges[j][0]]!=1e9 && dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
            {
                dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
            }
        }
    }
    return dist[dest];
}