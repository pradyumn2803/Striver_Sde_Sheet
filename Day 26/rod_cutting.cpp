
int cutRod(vector<int> &price, int N)
{
    int sz=price.size();
//     vector<vector<int>> dp(sz,vector<int>(N+1,0));
    vector<int> prev(N+1,0);
    
    for(int i=0;i<=N;i++) prev[i]=(i*price[0]);
    
    for(int ind=1;ind<sz;ind++)
    {
        for(int n=0;n<=N;n++)
        {
            int not_take=prev[n];
            int take=-1e9;
            if((ind+1)<=n) take=price[ind]+prev[n-(ind+1)];
            prev[n]=max(take,not_take);
        }
    }
    return prev[N];
	// Write your code here.
}
