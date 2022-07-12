struct Node
{
    Node* links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
    
    Node *get(int bit)
    {
        return links[bit];
    }
};

class Trie
{
private:
    Node* root;
public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(int num)
    {
        Node* node=root;
        
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int maxXor(int num)
    {
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(node->containsKey(!bit))
            {
               maxNum=maxNum | (1<<i); 
               node=node->get(!bit);
            }
            else
            {
               node=node->get(bit);
            }
        }
        return maxNum;
    }
};

int maximumXor(vector<int> A)
{
    int n = A.size();
    Trie trie;
    for(auto &it: A) trie.insert(it);
    
    int maxi=0;
    
     for(int y=0;y<n;y++)
     {
         maxi=max(maxi,trie.maxXor(A[y]));
     }
    
    return maxi;
}