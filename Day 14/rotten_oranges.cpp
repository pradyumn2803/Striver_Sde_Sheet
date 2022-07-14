#include<queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    if(grid.empty()) return 0;
    int total=0,cnt=0,days=0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]!=0) total++;
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    int dx[]={-1,1,0,0};
    int dy[]={0,0,1,-1};
    while(!q.empty())
    {
        int size=q.size();
        cnt+=size;
        
        while(size--)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1)
                {
                    q.push({newx,newy});
                    grid[newx][newy]=2;
                }
            }
        }
        if(!q.empty()) days++;
    }
    return (total==cnt)?days:-1;
}