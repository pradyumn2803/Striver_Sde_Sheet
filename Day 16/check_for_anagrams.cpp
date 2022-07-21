bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n = str1.size();
    int m = str2.size();
    
    if(n!=m) return 0;
    vector<int> mp(26,0);
    
    for(int i=0;i<n;i++)
    {
        mp[str1[i]-'a']++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(mp[str2[i]-'a']==0) return 0;
    }
   
    return 1;
}