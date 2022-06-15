bool ispossible(int row,int col,int n,vector<vector<int>> arr)
{
    int duprow=row;
    int dupcol=col;
    
    while(row>=0 && col>=0)
    {
        if(arr[row][col]==1) return false;
        row--;
        col--;
    }
    
    row=duprow;
    col=dupcol;
    
    while(row>=0)
    {
        if(arr[row][col]==1) return false;
        row--;
    }
    
    row=duprow;
    col=dupcol;
    
    while(row>=0 && col<n)
    {
        if(arr[row][col]==1) return false;
        row--;
        col++;
    }
    return true;
}

void f(int row,int n,vector<vector<int>> board,vector<vector<int>> &ans)
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
        if(ispossible(row,col,n,board))
        {
            board[row][col]=1;
            f(row+1,n,board,ans);
            board[row][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {

    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    f(0,n,board,ans);
    return ans;
}