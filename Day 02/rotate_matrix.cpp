
void rotateMatrix(vector<vector<int>> &mat, int m, int n)
{
    int row = 0, col = 0;
    int prev, cur;

    while (row < m && col < n)
    {
 
        if (row + 1 == m || col + 1 == n)
            break;

        prev = mat[row + 1][col];

        for (int i = col; i < n; i++)
        {
            cur = mat[row][i];
            mat[row][i] = prev;
            prev = cur;
        }
        row++;

        for (int i = row; i < m; i++)
        {
            cur = mat[i][n-1];
            mat[i][n-1] = prev;
            prev = cur;
        }
        n--;

        if (row < m)
        {
            for (int i = n-1; i >= col; i--)
            {
                cur = mat[m-1][i];
                mat[m-1][i] = prev;
                prev = cur;
            }
        }
        m--;

        if (col < n)
        {
            for (int i = m-1; i >= row; i--)
            {
                cur = mat[i][col];
                mat[i][col] = prev;
                prev = cur;
            }
        }
        col++;
    }

}