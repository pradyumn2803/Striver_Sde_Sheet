void f(int i,int j,int n,int di[],int dj[],vector<vector<int>>&maze,vector<vector<int>> &vis,vector<vector<int>> &ans,vector<vector<int>> &grid)
{
    if(i==n-1 && j==n-1)
    {
        grid[i][j]=1;
        vector<int> temp;
        
        for(auto q:grid)
        {
            for(auto w:q )
            {
                temp.push_back(w);
            }
        }
        ans.push_back(temp);
        return ;
    }
    
    for(int k=0;k<4;k++)
    {
        int newi=i+di[k];
        int newj=j+dj[k];
        
        if(newi>=0 && newi<n && newj>=0 && newj<n && maze[newi][newj]==1 && vis[newi][newj] == 0)
        {
            vis[i][j]=1;
            grid[i][j]=1;
            f(newi,newj,n,di,dj,maze,vis,ans,grid);
            vis[i][j]=0;
            grid[i][j]=0;
        }
    }
}


vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<int>> ans;
    vector<vector<int>> grid(n,vector<int>(n,0));
    int di[]={1,0,0,-1};
    int dj[]={0,-1,1,0};
    
    if(maze[0][0]==1) f(0,0,n,di,dj,maze,vis,ans,grid); 
    return ans;
}