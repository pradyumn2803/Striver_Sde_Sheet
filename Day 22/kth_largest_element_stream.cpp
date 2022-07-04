#include<queue>
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    
public:
    Kthlargest(int k, vector<int> &arr) {
       this->k=k;
       for(int i=0;i<arr.size();i++) pq.push(arr[i]);
       while(pq.size()>k) pq.pop();
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        pq.pop();        
    }

    int getKthLargest() {
       // Write your code here.
        return pq.top();
    }

};