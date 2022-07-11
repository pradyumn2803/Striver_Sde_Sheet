#include<algorithm>
#include<unordered_set>
bool wordBreak(vector < string > & arr, int n, string & target) {
    int sz=target.size();
    vector<int> dp(sz+1,0);
    
    unordered_set<string> hshset(arr.begin(),arr.end());
 
    dp[sz]=1;
    
    for(int i=sz-1;i>=0;i--)
    {
        string ss="";
        for(int ind=i;ind<sz;ind++)
        {
            ss+=target[ind];
            if(hshset.find(ss)!=hshset.end() && dp[ind+1])
            {
                dp[i]= 1;
            }
        }
    }
    return dp[0];
}