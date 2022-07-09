
int editDistance(string s, string t)
{
	int n=s.size();
    int m=t.size();
//     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> prev(m+1,0),cur(m+1,0);
    
    for(int i=0;i<=m;i++)
    {
        prev[i]=i;
    }
    
    for(int i=1;i<=n;i++)
    {
        cur[0]=i;
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]) cur[j]=prev[j-1];
    		else
            {
                int ins=1+cur[j-1];
                int del=1+prev[j];
                int rep=1+prev[j-1];

                cur[j]=min(ins,min(del,rep));
            }
        }
        prev = cur;
    }
    return prev[m];
}