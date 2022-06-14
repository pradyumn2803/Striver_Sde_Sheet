#include<map>
void f(int n,string a,vector<string> &ans,string w,int mp[])
{
    if(w.size()==n)
    {
        ans.push_back(w);
        return ;
    }
    
    for(int ind =0;ind<n;ind++)
    {
        if(mp[ind]==0)
        {
            mp[ind]=1;
            f(n,a,ans,w+a[ind],mp);
            mp[ind]=0;
        }
    }
}

vector<string> findPermutations(string &s) {
    int n = s.size();
    vector<string> ans;
    int mp[n];
    
    for(int i=0;i<n;i++) mp[i]=0;
    f(n,s,ans,"",mp);
    return ans;
}