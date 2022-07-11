#include<vector>
long countWaysToMakeChange(int *arr, int n, int value)
{
//     vector<vector<long>> dp(n,vector<long>(value+1,0));
    vector<long> prev(value+1,0),cur(value+1,0);
    for(int i=0;i<=value;i++) prev[i]=(i%arr[0]==0);
    
    for(int ind=1;ind<n;ind++)
    {
        for(int sum=0;sum<=value;sum++)
        {
            long not_take=prev[sum];
            long take=0;
            if(arr[ind]<=sum) take=cur[sum-arr[ind]];

            cur[sum]=(take+not_take);
        }
        prev=cur;
    }
    return prev[value];
    //Write your code here
}