#include<algorithm>
class DSU
{
private: vector<int> parent,rank;
public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    int find_parent(int node)
    {
        if(parent[node]==node) return node;
        
        return parent[node]=find_parent(parent[node]);
    }
    
    void UnionRank(int a,int b)
    {
        int pa=find_parent(a);
        int pb=find_parent(b);
        
        if(pa==pb) return ;
        
        if(rank[pa]<rank[pb]) 
        {
            parent[pa]=pb;
        }
        else if(rank[pa]>rank[pb]) 
        {
            parent[pb]=pa;
        }
        else
        {
            parent[pb]=pa;
            rank[pa]+=1;
        }
    }
};

static bool cmp(vector<int> &a,vector<int> &b)
{
    return a[2]<b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	DSU dsu(n+1);
    
    sort(graph.begin(),graph.end(),cmp);
    int weights=0;
    for(int i=0;i<m;i++)
    {
        if(dsu.find_parent(graph[i][0])!=dsu.find_parent(graph[i][1]))
        {
            dsu.UnionRank(graph[i][0],graph[i][1]);
            weights+=graph[i][2];
        }
    }
    
    return weights;
}