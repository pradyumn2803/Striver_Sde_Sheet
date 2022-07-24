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