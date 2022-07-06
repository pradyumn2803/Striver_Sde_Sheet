class DSU{
  private: vector<int> parent,size,rank;
public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int find_parent(int node)
    {
        if(parent[node]==node) return node;
        
        return parent[node]=find_parent(parent[node]);
    }
    
    void UnionSize(int n1,int n2)
    {
        int u=find_parent(n1);
        int v=find_parent(n2);
        if(u==v) return ;
        
        if(size[u]<size[v])
        {
            parent[u]=v;
            size[v]+=size[u];
        }
        
        else
        {
            parent[v]=u;
            size[u]+=size[v];
        }
    }
    
    void UnionRank(int n1,int n2)
    {
        int u=find_parent(n1);
        int v=find_parent(n2);
        if(u==v) return ;
        
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else
        {
            parent[u]=v;
            rank[v]++;
        }
    }
};

int getTotalIslands(int** arr, int n, int m)
{
    DSU dsu(n*m+1);
    int islands=0;
    
    int dx[]={0,1,0,-1,1,-1,1,-1};
    int dy[]={1,0,-1,0,1,-1,-1,1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                islands++;
                int ind1=(i*m)+(j+1);
                for(int dir=0;dir<8;dir++)
                {
                    int newi=i+dx[dir];
                    int newj=j+dy[dir];
                    
                    int ind2=(newi*m)+(newj+1);
                    if(newi>=0 && newi<n && newj>=0 && newj<m && arr[newi][newj]==1 && dsu.find_parent(ind1)!=dsu.find_parent(ind2))
                    {
                        islands--;
                        dsu.UnionSize(ind1,ind2);
                    }
                }
            }
        }
    }
    return islands;
}
