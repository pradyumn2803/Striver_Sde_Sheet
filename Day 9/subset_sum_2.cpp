#include<algorithm>
void f(int i,int n,vector<vector<int>>& ans,vector<int> &arr,vector<int> &v)
{
    ans.push_back(v);
    for(int ind=i;ind<n;ind++)
    {
        if(arr[ind]==arr[ind-1] && i!=ind) continue;
        v.push_back(arr[ind]);
        f(ind+1,n,ans,arr,v);
        v.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> v;
    sort(arr.begin(),arr.end());
    f(0,n,ans,arr,v);
    return ans;
}