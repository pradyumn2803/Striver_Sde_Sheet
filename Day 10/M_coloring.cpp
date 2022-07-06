bool ispossible(int node,int c,int n,vector<vector<int>> &mat,vector<int> &color, int m)
{
    for(int i=0;i<n;i++)
    {
        if(mat[node][i]==1 && color[i]==c) return false;
    }
    return true;
}

bool solve(int ind,int n,vector<vector<int>> &mat,vector<int> &color, int m)
{
    if(ind==n) return true;
    
    for(int i=1;i<=m;i++)
    {
        if(ispossible(ind,i,n,mat,color,m)) 
        {
            color[ind]=i;
            if(solve(ind+1,n,mat,color,m)) return true;
            color[ind]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> color(n,0);
    if(solve(0,n,mat,color,m)) return "YES";
    return "NO";
}