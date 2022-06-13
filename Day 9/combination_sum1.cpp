
void f(int i,int n,int target,vector<vector<int>> &ans,vector<int> &v,vector<int> &arr)
{
    if(i==n)
    {
        if(target==0)
        {
            ans.push_back(v);
        }
        return ;
    }
    
    v.push_back(arr[i]);
    f(i+1,n,target-arr[i],ans,v,arr);
    v.pop_back();
    
    f(i+1,n,target,ans,v,arr);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;
    
    f(0,n,k,ans,v,arr);
    return ans;
}