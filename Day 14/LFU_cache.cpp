#include<map>
struct node
{
    int key,value,cnt;
    node *next,*prev;
    node(int _key,int _value)
    {
        key=_key;
        value=_value;
        cnt=1;
    }
};

class list
{
public:
    int size;
    node* head;
    node* tail;
    list()
    {
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void addnode(node* n)
    {
        node* temp=head->next;
        head->next=n;
        temp->prev=n;
        n->next=temp;
        n->prev=head;
        size++;
    }
    
    void deletenode(node* n)
    {
        node* prevn=n->prev;
        node* nnext=n->next;
        prevn->next=n->next;
        nnext->prev=n->prev;
        size--;
    }
};

class LFUCache
{
    map<int,node*> keynode;
    map<int,list*> freqmap;
    int minfreq;
    int cursize,maxsize;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        maxsize=capacity;
        cursize=0;
        minfreq=0;
    }
    
    void updatefreqlistmap(node* cur)
    {
        keynode.erase(cur->key);
        freqmap[cur->cnt]->deletenode(cur);
        
        if(cur->cnt==minfreq && freqmap[cur->cnt]->size==0)
        {
            minfreq++;
        }
        
        list * newList=new list();
        
        if(freqmap.find(cur->cnt+1)!=freqmap.end())
        {
            newList=freqmap[cur->cnt+1];
        }
        cur->cnt+=1;
        newList->addnode(cur);
        freqmap[cur->cnt]=newList;
        keynode[cur->key]=cur;
    }
    
    int get(int key)
    {
        // Write your code here.
        if(keynode.find(key)!=keynode.end())
        {
            node* cur=keynode[key];
            int val=cur->value;
            updatefreqlistmap(cur);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxsize==0) return ;
        if(keynode.find(key)!=keynode.end())
        {
            node* cur=keynode[key];
            cur->value=value;
            updatefreqlistmap(cur);
        }
        else 
        {
            if(maxsize==cursize)
            {
                list* newlist=freqmap[minfreq];
                keynode.erase(newlist->tail->prev->key);
                newlist->deletenode(newlist->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            
            list* newlist=new list();
            
            if(freqmap.find(minfreq)!=freqmap.end())
            {
                newlist=freqmap[minfreq];
            }
            
            node* n=new node(key,value);
            newlist->addnode(n);
            keynode[key]=n;
            freqmap[minfreq]=newlist;
        }
    }
};









