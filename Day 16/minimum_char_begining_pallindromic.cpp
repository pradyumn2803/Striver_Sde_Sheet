#include<algorithm>
vector<int> find_lps(string str)
{
    vector<int> lps(str.size()+1,0);
    int j=0;
    for(int i=1;i<str.size();i++)
    {
        while(j>0 && str[i]!=str[j]) j=lps[j-1];
        if(str[i]==str[j]) j++;
        lps[i]=j;
    }
    return lps;
}

int minCharsforPalindrome(string str) {
	// Write your code here.
	string rev=str;
    reverse(rev.begin(),rev.end());
    string new_str=str+'$'+rev;
    vector<int> lps=find_lps(new_str);
    return str.size()-lps[new_str.size()-1];
}
