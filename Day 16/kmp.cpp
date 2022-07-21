vector<int> pre_arr(string p)
{
    int n=p.size();
    vector<int> pi(n,0);
    
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) j++;
        pi[i]=j;
    }
    return pi;
}

bool findPattern(string p, string s)
{
    // Write your code here.
    vector<int> prefix=pre_arr(p);
    
    int i=0,j=0;
    
    while(i<s.size())
    {
        if(s[i]==p[j]) 
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0) j=prefix[j-1];
            else i++;
        }
        if(j==p.size()) return true;
    }
    return false;
}