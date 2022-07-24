#include<algorithm>
class heap{
private: 
    int heapsize; 
    int size;
    int pq[100001];
public:
    
    heap()
    {
        heapsize=0;
        size=(int)1e5+1;       
    }
    
    void push(int val)
    {
        if(heapsize>=size) return ;
        pq[heapsize]=val;
        
        int cur=heapsize;      
        while(cur>0 && pq[(cur-1)/2]>pq[cur])
        {
            swap(pq[(cur-1)/2],pq[cur]);
            cur=(cur-1)/2;
        }
        heapsize+=1;
    }
    
    int pop()
    {
        if(heapsize<=0) return -1;
        
        int popped=pq[0];
        pq[0]=pq[heapsize-1];
        heapsize-=1;
        int cur=0;
        
        while((2*cur+1)<heapsize)
        {
            int child;
            if((2*cur+2)==heapsize)
            {
                child=2*cur+1;
            }
            else
            {
                child=(pq[2*cur+1]<pq[2*cur+2])?2*cur+1:2*cur+2;
            }
            
            if(pq[cur]>pq[child])
            {
                swap(pq[cur],pq[child]);
                cur=child;
            }
            else break;
        }
        return popped;
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    heap h;
    
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0) h.push(q[i][1]);
        else ans.push_back(h.pop());
    }
    return ans;
}
