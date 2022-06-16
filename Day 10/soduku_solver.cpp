bool isvalid(int row,int col,int matrix[9][9],int num)
{
    for(int i=0;i<9;i++)
    {
        if(matrix[i][col]==num) return false;
        
        if(matrix[row][i]==num) return false;
        
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
    }
    return true;
}
bool solve(int matrix[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matrix[i][j]==0)
            {
                for(int n=1;n<=9;n++)
                {
                    if(isvalid(i,j,matrix,n))
                    {
                        matrix[i][j]=n;
                    
                        if(solve(matrix)==true) return true;
                        else matrix[i][j]=0;
                    }
                }
               return false;
            }

        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    solve(matrix);
}
