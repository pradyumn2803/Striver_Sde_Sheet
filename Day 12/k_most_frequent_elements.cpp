// Approach 1-Priority queue
#include<queue>
#include<map>
#include<algorithm>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int,int> mp;
    
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto i:mp)
    {
        pq.push({i.second,i.first});
    }
    
    vector<int> v;
    while(k--)
    {
        v.push_back(pq.top().second);
        pq.pop();
    }
    sort(v.begin(),v.end());
    return v;
}

// Approach 2-Bucket Sort

#include<map>
#include<algorithm>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int,int> mp;
    
    for(auto i:arr) mp[i]++;
    
    vector<int> bucket[n];
    
    for(auto i:mp)
    {
        int freq=i.second;
        bucket[freq].push_back(i.first);
    }
    
    int cur=0;
    vector<int> ans(k);
    for(int i=n-1;i>=0 && k>0 ;i--)
    {
        if(bucket[i].size()==0) continue;
        
        for(int num:bucket[i])
        {
            ans[cur++]=num;
            k--;
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}