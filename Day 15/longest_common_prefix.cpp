// Approach 1
#include<algorithm>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    sort(arr.begin(),arr.end());
    
    string a=arr[0];
    string b=arr[n-1];
    string ans="";
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==b[i]) ans+=a[i];
        else break;
    }
    return ans;
}

// Approach 2

struct node
{
    node* links[26];
    int cnt_prefix=0;
    
    bool contains_key(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void put(char ch,node* newnode)
    {
        links[ch-'a']=newnode;
    }

    void prefix_count()
    {
        ++cnt_prefix;
    }
};

class Trie
{
private: node*root;
public:
    Trie()
    {
        root=new node();
    }
    
    string InsertAndCheckLCP(string &word,int sz)
    {
        node* Node=root;
        string ans="";
        for(int i=0;i<word.size();i++)
        {
            if(!Node->contains_key(word[i]))
            {
                Node->put(word[i],new node());
                Node->cnt_prefix=1;
            }
            else Node->prefix_count();
            if(Node->cnt_prefix==sz) ans+=word[i];
            Node=Node->get(word[i]);
        }
        return ans;
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie trie;
    string res;
    for(int i=0;i<n;i++)
    {
        res=trie.InsertAndCheckLCP(arr[i],n);
    }

    return res;
}






