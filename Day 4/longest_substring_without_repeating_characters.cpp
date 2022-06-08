#include<unordered_map>
int uniqueSubstrings(string input)
{
    int n=input.size();
    int left=0,right=0;
    int len=0;
    unordered_map<char,int> mp;
    while(right<n)
    {
        if(mp.find(input[right])!=mp.end()) left=max(left,mp[input[right]]+1);
        
        mp[input[right]]=right;
        len=max(len,right-left+1);
        right++;
    }
    return len;
}