
void f(int row,int n,vector<vector<int>> board,vector<vector<int>> &ans,vector<int> &up,vector<int>                 &up_left,vector<int> &up_right)
{
    if(row==n)
    {
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a.push_back(board[i][j]);
            }
        }
        ans.push_back(a);
        return ;
    }
    
    for(int col=0;col<n;col++)
    {
        if(up[col]==0 && up_right[row+col]==0 && up_left[n-1+col-row]==0)
        {
            board[row][col]=1;
            up[col]=1;
            up_right[row+col]=1;
            up_left[n-1+col-row]=1;
            f(row+1,n,board,ans,up,up_left,up_right);
            up[col]=0;
            up_right[row+col]=0;
            up_left[n-1+col-row]=0;
            board[row][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {

    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    vector<int> up(n,0),up_left(2*n-1,0),up_right(2*n-1,0);
    f(0,n,board,ans,up,up_left,up_right);
    return ans;
}