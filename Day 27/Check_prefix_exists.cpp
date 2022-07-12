struct Node
{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void setEnd()
    {
        flag=true;
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    private: Node* root;
    
    public:
    
    Trie()
    {
        root=new Node();    
    }
    
    void insert(string &word)
    {
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool IFPrefixExists(string &word)
    {
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
            if(node->isEnd()==false) return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    
    for(auto &it:a)
    {
        trie.insert(it);
    }
    string longest="";
    for(auto &it:a)
    {
        if(trie.IFPrefixExists(it))
        {
            if(it.size()>longest.size())
            {
                longest=it;
            }
            else if(it.size()==longest.size() && it<longest)
            {
                longest=it;
            }
        }
    }
    return (longest=="")?"None":longest;
}









