int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 1e9));

    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]][edges[i][1]] = edges[i][2];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    adj[i][j] = 0;
                else if (adj[i][k] == 1e9 || adj[k][j] == 1e9)
                    continue;
                else
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    return adj[src][dest];
}