#include<vector>
int ispallindrome(int i,int j,string &str)
{
	while(i<=j)
	{
		if(str[i++]!=str[j--]) return 0;
	}
	return 1;
}
int palindromePartitioning(string str) {
    int n=str.size();
	vector<int> dp(n+1,0);
	dp[n]=0;
	
	for(int i=n-1;i>=0;i--)
	{
		int min_cost=1e9;
		for(int j=i;j<n;j++)
		{
			if(ispallindrome(i,j,str))
			{
				int cost=1+dp[j+1];
				min_cost=min(cost,min_cost);
			}
		}
		dp[i]= min_cost;
	}
	return dp[0]-1;
}
