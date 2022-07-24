#include<queue>
#include<set>
#include<algorithm>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;
    vector<int> ans;
    
    pq.push({a[0]+b[0],{0,0}});
    s.insert({0,0});

    while(ans.size()!=k)
    {
        auto p=pq.top();
        int val=p.first;
        int x=p.second.first;
        int y=p.second.second;
        pq.pop();
        ans.push_back(val);
        
        if(x+1<n && s.find({x+1,y})==s.end())
        {
            pq.push({a[x+1]+b[y],{x+1,y}});
            s.insert({x+1,y});
        }
        
        if(y+1<n && s.find({x,y+1})==s.end())
        {
            pq.push({a[x]+b[y+1],{x,y+1}});
            s.insert({x,y+1});
        }
    }
    return ans;
}