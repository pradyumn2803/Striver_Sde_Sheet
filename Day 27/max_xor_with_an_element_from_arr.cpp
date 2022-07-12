#include<algorithm>
struct Node
{
    Node* links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
    
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
    
};

class Trie
{
private:
    Node *root;
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
            int bit=(num>>i)&1;
            
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int MaxXor(int num)
    {
        Node* node=root;
        int mxxor=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            
            if(node->containsKey(!bit))
            {
                mxxor=mxxor | (1<<i);
                node=node->get(!bit);
            }
            else node=node->get(bit);
        }
        return mxxor;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    int n = arr.size();
    int q =queries.size();
    vector<int> ans(q,0);
    sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>> oQ;
    Trie trie;
    for(int i=0;i<queries.size();i++)
    {
        oQ.push_back({queries[i][1],{queries[i][0],i}});
    }
    
    sort(oQ.begin(),oQ.end());
    
    int ind=0;
    for(int i=0;i<queries.size();i++)
    {
        int ai=oQ[i].first;
        int xi=oQ[i].second.first;
        int qind=oQ[i].second.second;
        
        while(ind<n && arr[ind]<=ai)
        {
            trie.insert(arr[ind]);
            ind++;
        }
        
        if(ind==0) ans[qind]=-1;
        else ans[qind]=trie.MaxXor(xi);
    }
    return ans;
}










