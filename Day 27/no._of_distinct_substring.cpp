class Node
{
    private:
        Node *links[26];
    public:
        bool containsKey(char ch)
        {
            return links[ch-'a'];
        }
        
        void put(char ch,Node* node)
        {
            links[ch-'a']=node;
        }
    
        Node* get(char ch)
        {
            return links[ch-'a'];
        }
    
};
int distinctSubstring(string &word) {
    //  Write your code here.
    Node *root=new Node();
    int cnt=0;
    int n = word.size();
    for(int i=0;i<n;i++)
    {
        Node* trie=root;
        for(int j=i;j<n;j++)
        {
            if(trie->containsKey(word[j])==false)
            {
                cnt++;
                trie->put(word[j],new Node());
            }
            trie=trie->get(word[j]);
        }
    }
    return cnt;
}
