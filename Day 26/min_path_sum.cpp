
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0);
//     return f(n-1,m-1,grid,dp);
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) temp[j]=grid[i][j];
            else
            {
                int up=0,left=0;
                up=grid[i][j];
                if(i>0) up+=prev[j];
                else up=1e9;
    			left=grid[i][j];
                if(j>0) left+=temp[j-1];
                else left=1e9;
                temp[j]=min(up,left);
            }
        }
        prev=temp;
    }
    return prev[m-1];
}