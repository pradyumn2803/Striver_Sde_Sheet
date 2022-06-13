#include<algorithm>
void f(int i,int n,vector<vector<int>> &ans,vector<int> &v,vector<int> &arr,int target)
{
    if(target==0)
    {
        ans.push_back(v);
        return ;
    }
    for(int ind=i;ind<n;ind++)
    {
        if(arr[ind-1]==arr[ind] && ind!=i) continue;
        if(arr[ind]>target) break;
        v.push_back(arr[ind]);
        f(ind+1,n,ans,v,arr,target-arr[ind]);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    
    vector<int> v;
    
    f(0,n,ans,v,arr,target);
    return ans;
}
