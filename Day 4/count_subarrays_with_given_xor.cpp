#include<unordered_map>
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int> mp;
    int n=arr.size();
    int ans=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        ans^=arr[i];
        
        if(ans==x) cnt++;
        if(mp.find(ans^x)!=mp.end())
        {
            cnt+=mp[ans^x];
        }
        mp[ans]+=1;
    }
    return cnt;
}