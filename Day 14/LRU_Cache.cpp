#include<unordered_map>
class LRUCache
{
public:
    class node
    {
     public:
        int key,val;
        node* next,*prev;
        
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    node* head=new node(-1,-1);
    node*tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*> mp;
    
    
    LRUCache(int capacity)
    {
        // Write your code here
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    
    void addNode(node* res)
    {
        node* temp=head->next;
        res->next=temp;
        res->prev=head;
        head->next=res;
        temp->prev=res;
    }
    
    void deleteNode(node *res)
    {
        node* delprev=res->prev;
        node* delnext=res->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key)
    {
        // Write your code here
        if(mp.find(key)!=mp.end())
        {
            node* res=mp[key];
            int value=res->val;
            mp.erase(key);
            deleteNode(res);
            addNode(res);
            mp[key]=head->next;
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key)!=mp.end())
        {
            node *res=mp[key];
            mp.erase(key);
            deleteNode(res);           
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};
