#include<algorithm>
void f(int i,int n,string &s,vector<string> &dictionary,string a,vector<string> &ans)
{
    if(i==n)
    {
//         a=a.substr(0,a.size()-1);
        ans.push_back(a);
        return ;
    }
    string ss="";
    for(int ind=i;ind<n;ind++)
    {
        ss+=s[ind];
        if(find(dictionary.begin(),dictionary.end(),ss)!=dictionary.end())
        {
            f(ind+1,n,s,dictionary,a+ss+" ",ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    int n=s.size();
    vector<string> ans;
    
    f(0,n,s,dictionary,"",ans);
    return ans;

}