
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int i=n-1;i>=0;i--)
    {
        for(int prev=i-1;prev>=-1;prev--)
        {
            int sum=dp[i+1][prev+1];
    
            if(prev==-1 || rack[prev]<rack[i])
            {
                sum=max(sum,rack[i]+dp[i+1][i+1]);
            }
            dp[i][prev+1]= sum;            
        }
    }
    return dp[0][0];
}