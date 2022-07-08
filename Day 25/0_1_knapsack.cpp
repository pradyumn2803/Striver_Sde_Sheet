int maxProfit(vector<int> &values, vector<int> &weights, int n, int W)
{
    vector<int> cur(W+1,0);
        
    for(int i=n-1;i>=0;i--)
    {
        for(int w=W;w>=0;w--)
        {
            if(weights[i]<=w)
            {
                cur[w]=max(cur[w],values[i]+cur[w-weights[i]]);
            }
        }
    }
	return cur[W];
}