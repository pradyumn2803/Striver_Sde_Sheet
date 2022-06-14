void f(int i,int n,string &a,vector<string> &ans)
{
    if(i>=n)
    {
        ans.push_back(a);
        return ;
    }
    
    for(int ind =i;ind<n;ind++)
    {
         swap(a[i],a[ind]);
         f(i+1,n,a,ans);
         swap(a[i],a[ind]);
    }
}

vector<string> findPermutations(string &s) {
    int n = s.size();
    vector<string> ans;

    f(0,n,s,ans);
    return ans;
}