vector<int> stringMatch(string &str, string &pat) {
    int n = str.size();
    int m = pat.size();
    int base=26;
    int mod=(int)1e9+7;
    vector<long long> power(n);
    power[0]=1;
    
    for(int i=1;i<n;i++)
    {
        power[i]=(power[i-1]*base)%mod;
    }
    
    vector<long long> hash(n+1,0);
    
    for(int i=0;i<n;i++)
    {
        hash[i+1]=(hash[i]+(str[i]-'A'+1)*power[i])%mod;
    }
    
    long long hashpattern=0;
    for(int i=0;i<m;i++)
    {
        hashpattern=(hashpattern+(pat[i]-'A'+1)*power[i])%mod;
    }
    
    int i=0;
    vector<int> ans;
    while((i+m-1)<n)
    {
        long long hashstr=(hash[i+m]+mod-hash[i])%mod;
        if(hashstr==hashpattern*power[i]%mod)
        {
            ans.push_back(i);
        }
        i++;
    }
    return ans;
}
