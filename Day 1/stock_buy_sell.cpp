#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    
    int n=prices.size();
    int profit=0,mini=prices[0];
    
    for(int i=1;i<n;i++)
    {
        mini=min(prices[i],mini);
        profit=max(profit,prices[i]-mini);
    }
    return profit;
}