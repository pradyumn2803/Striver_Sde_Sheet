#include<algorithm>

bool ispallindrome(string s,int start,int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}

void f(int i,int n,string s,vector<vector<string>> &res,vector<string> &path)
{
    if(i==n)
    {
        res.push_back(path);
        return ;
    }
    
    for(int ind=i;ind<n;ind++)
    {
        if(ispallindrome(s,i,ind))
        {
            path.push_back(s.substr(i,ind-i+1));
            f(ind+1,n,s,res,path);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res;
    vector<string> path;
    int n=s.size();
    f(0,n,s,res,path);
    return res;
}