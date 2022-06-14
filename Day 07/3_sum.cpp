#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        int find=K-arr[i];
        
        int front=i+1,back=n-1;
        
        while(front<back)
        {
            if((arr[front]+arr[back])<find)  front++;
            else if((arr[front]+arr[back])>find) back--;
            else
            {
                vector<int> triplet(3);
                triplet[0]=arr[i];
                triplet[1]=arr[front];
                triplet[2]=arr[back];
                ans.push_back(triplet);
                
                while(front < back && arr[front]==triplet[1]) ++front;
                
                while(front < back && arr[back]==triplet[2]) --back;
                
            } 
        }
        while(i+1<n && arr[i+1]==arr[i]) i++; 
    }
    return ans;
}