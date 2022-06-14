#include<unordered_map>
int LongestSubsetWithZeroSum(vector<int> arr) {
    unordered_map<int,int> mp;   
    int n=arr.size();
       int maxi=0;
       int sum=0;
      for(int i=0;i<n;i++)
      {          
            sum+=arr[i];
            if(sum==0)
            {
               maxi=i+1;
            }
          	else 
            {
                if(mp.find(sum)!=mp.end())
                {
                    maxi=max(maxi,i-mp[sum]);
                }
                else
                {
                    mp[sum]=i;
                }
            }
    }
	return maxi;
}