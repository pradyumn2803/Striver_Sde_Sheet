#include<map>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    map<int,int> mp;
    int i=1,j=k;
	for(int w=0;w<k;w++) mp[arr[w]]++;
    ans.push_back(mp.size());
    while(j<arr.size())
    {        
        mp[arr[i-1]]--;
        if(mp[arr[i-1]]==0) mp.erase(arr[i-1]);       
        mp[arr[j]]++; 
        ans.push_back(mp.size());
        i++;
        j++;
    }
    return ans;
}
