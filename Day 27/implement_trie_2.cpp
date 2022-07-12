struct Node{
    Node* links[26];
    int count_prefix=0;
    int count_endwith=0;
    
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
    
    void increase_end()
    {
        count_endwith++;
    }
    
    void increase_prefix()
    {
        count_prefix++;
    }
    
    void decrease_prefix()
    {
        count_prefix--;
    }
    
    void decrease_end()
    {
        count_endwith--;
    }
    
    int ends_with()
    {
        return count_endwith;
    }
    
    int prefix()
    {
        return count_prefix;
    }
};

class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
        root= new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increase_prefix();
        }
        node->increase_end();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->ends_with();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->prefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i])) return ;
            node=node->get(word[i]);
            node->decrease_prefix();
        }
        node->decrease_end();
    }
};
